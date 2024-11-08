#include <iostream>

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

	std::cout << static_cast<Base&>(d).value << std::endl; // 20

	// 핵심 : 이름이 동일한 멤버데이타가 있을때
	//		  기반 클래스이 멤버 데이타 접근하려면
	//		  객체를 기반 클래스의 참조 타입으로 캐스팅하면됩니다.

}
