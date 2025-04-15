#include <iostream>
// 85 page


struct Base
{
	int value{ 10 };
};
struct Derived : public Base
{
	int value{ 20 };
};
int main()
{
	Derived d;

	std::cout << d.value << std::endl;  // Derived 가 추가한 value 20

	// 기반 클래스(Base)에서 상속받은 value 접근하려면 캐스팅 필요
	std::cout << static_cast<Base>(d).value << std::endl; // 10

}

