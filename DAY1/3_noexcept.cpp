// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// C++11 noexcept 의 용도
// 1. 함수가 예외가 없는지 "조사" 하거나
// 2. 함수가 예외가 없음을 "표시" 하기 위해서 사용

void foo() 
{
}
void goo()
{
}

int main()
{
	// noexcept( 함수 호출 표현식 ) : 표현식 때로 호출했을때
	//								 예외 가능성이 없으면 true
	bool b1 = noexcept(foo());
	bool b2 = noexcept(goo());

	std::cout << std::boolalpha; // 1, 0 이 아닌 true, false 로 해달라
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}




