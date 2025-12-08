// 3_noexcept - 14 page
#include <iostream>
#include <exception>
//
// C++11 추가된, noexcept 용도
// 1. 함수가 예외가 없음을 알릴때 사용
// 2. 함수가 예외가 없는지 조사할때 사용

// #1. 컴파일러는 함수가 예외가 있는지 없는지 함수 구현을 보고 조사할수 없습니다.
// => 개발자가 함수 signature 로 알려야 하고
// => 컴파일러는 signature 를 보고 판단
// void foo()             // 예외 가능성이 있다
// void foo() noexcept    // 예외 가능성이 없다
// void foo() noexcept(true) // 예외 가능성이 없다
void foo() noexcept(false)   // 예외 가능성이 있다
{
}
void goo()
{
}

int main()
{
	// #2. 예외가 없는지 조사
	// bool b = noexcept( 함수 호출식 ); // "함수호출식" 처럼 호출시 예외가 없는지 조사
	bool b1 = noexcept(foo());
	bool b2 = noexcept(goo());

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	// #3. 왜 예외가 있는지/없는지를 확인하는가 ?
	// => 안전한 코드 작성시, 예외 없는 방식을 선택하고 싶을때가 있다
	if (noexcept(foo()))	
	{
		foo(); // 예외가 없다... 사용!!
	}
	else
	{	
		// foo() 가 빠르지만, 예외가 있다면
		// => 예외 없는 다른 기술 사용
		goo(); 
	}

	// unevaluated expression : 실행할때만 동작하지 않고 컴파일 할때만 사용하는
	//							표현식
	bool b = noexcept(foo()); // foo() 가 실행되는 것 아님.
							  // 단지, 컴파일 할때만 조사.

	int n = sizeof(main()); // 반환값의 크기 조사. int 이므로 4바이트
}

// 왜 noexcept 를 사용하나요 ?

// 1. move 를 이해하기 위해 <= 모든 C++ 개발자가 알아야 합니다
// 2. 최적화를 위해 <= 오픈 소스 개발자가 많이 사용..

// 3. 예외를 완벽히 이해 하지 못하면 사용하지 마세요.. move 에서만 사용하세요

// godbolt.org 접속해 보세요. C++ 언어 선택후, 왼쪽창에 아래 코드 넣으세요
#include <string>

void foo()
{
	std::string s = "hello";
}


