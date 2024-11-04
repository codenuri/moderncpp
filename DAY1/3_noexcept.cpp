// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept
// #1. 함수가 예외가 있는지 없는지 조사 <- 교재에 추가
// #2. 함수가 예외가 없음을 알리기 위해 사용

// 모든 함수는 "예외 가능성" 이 있다고 생각하게 됩니다.
// => 컴파일러는 구현을 조사하지는 않습니다.
// => 함수가 예외가 없다면, 함수 만드는 개발자가 알려주어야 합니다.
void foo() 
{
}
void goo() noexcept		// 함수가 예외가 없다고 알려주는 코드
{
}

int main()
{
	bool b1 = noexcept( foo() ); // noexcept( 함수 호출표현식 )
	bool b2 = noexcept( goo() ); // 원리
						// 함수 선언뒤에 "noexcept" 가 있는지 조사

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}




