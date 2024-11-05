#include <iostream>
// 85 page
struct Base
{
	int value = 10; 
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl; // 20

	std::cout << static_cast<Base>(d).value << std::endl; // 10
	std::cout << static_cast<Base&>(d).value << std::endl; // 10


	static_cast<Base>(d).value = 20; // error. 임시객체.value = 20
	static_cast<Base&>(d).value = 20; // ok. d의 base_value = 20
}

// 결국, 임시객체는
// 1. 사용자가 의도적으로 만들기도 하고
// => 함수인자로 전달 
// => draw_line( Point(1,1), Point(10,20));

// 2. 사용자가 작성한 코드 때문에 생성되기 도 합니다.
// => 값을 반환하는 함수
// => 값으로 캐스팅.. 
