// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept
// #1. 함수가 예외가 있는지 없는지 조사 <- 교재에 추가
// #2. 함수가 예외가 없음을 알리기 위해 사용

void foo() 
{
}
void goo()
{
}

int main()
{
	bool b1 = noexcept( foo() ); // noexcept( 함수 호출표현식 )
	bool b2 = noexcept( goo() );

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}




