// 3_noexcept - 14 page
#include <iostream>
#include <exception>
//
// C++11 추가된, noexcept 용도
// 1. 함수가 예외가 없음을 알릴때 사용
// 2. 함수가 예외가 없는지 조사할때 사용

void foo() 
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
	bool b2 = noexcept(foo());

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}




