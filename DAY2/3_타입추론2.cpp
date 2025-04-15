#include <iostream>
// 템플릿사용시 추론된 타입을 확인하려면
// 방법 #1. godbolt.org 에서 어셈블리 코드 보세요 - 권장
// 방법 #2. 함수 이름(signature 포함)출력

// 주의 : RTTI 기술로 조사하지 마세요..
//       아래 foo 함수 마지막 부분 주석 참고!

template<typename T> void foo(T a)
{
	// __func__ : 함수 이름을 담은 매크로 (C++ 표준)
//	std::cout << __func__ << std::endl;

	// __FUNCSIG__ : signature 를 포함한 함수 이름(C++표준아님, vs 전용)
	// __PRETTY_FUNCTION__ : g++, clang++ 에서만 가능. 
	// std::cout << __FUNCSIG__ << std::endl;


	// 아래 방법은 절대 사용하지 마세요 
	// => C++ 의 RTTI 기술
	// => const, volatile, reference 를 출력할수 없다.
	std::cout << typeid(T).name() << std::endl;
}


int main()
{
	// #1. 타입을 명시적으로 전달하는 경우
	// => 사용자가 전달한 타입을 사용
	foo<const int>(3.4);

	// #2. 타입을 명시적으로 전달하지 않은 경우
	// => 컴파일러가 인자로 보고 타입을 추론
	foo(10); // T : int
	foo(3.4);// T : double
}