// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// C++11 noexcept 의 용도
// 1. 함수가 예외가 없는지 "조사" 하거나
// 2. 함수가 예외가 없음을 "표시" 하기 위해서 사용

// 컴파일러가 함수 호출이 유효한지 조사할때
// => 함수 구현을 조사할수는 없습니다.
//    (함수 선언만 보고 호출 가능 여부를 판단하므로)

// => 따라서, 모든 함수는 예외 가능성이 있습니다.

// => 예외가 없음을 보장할수 있다면, 함수 제작자가
//    알려 주어야 합니다.

void foo() noexcept    // 함수 가 예외가 없음을 알릴때 사용
{
}
void goo()	
{
}

int main()
{
	// noexcept( 함수 호출 표현식 ) : 표현식 때로 호출했을때
	//								 예외 가능성이 없으면 true
	// 원리 : 함수 선언뒤에 noexcept 가 표기되어 있는지 조사하는것					
	bool b1 = noexcept(foo());	// true
	bool b2 = noexcept(goo());	// false

	std::cout << std::boolalpha; // 1, 0 이 아닌 true, false 로 해달라
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}




