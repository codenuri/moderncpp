// 7_생성자 상속 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
	
	// C++ 문법 : 생성자는 상속될수 없다.
	// C++11 생성자 상속 문법 : 기반 클래스 생성자를 상속 받게 하는 문법
	using Base::Base;   // using 클래스이름::생성자이름
};

int main()
{
	// 아래 2줄을 생각해 봅시다.
	Derived d1;		// ok
	Derived d2(5);	// ok
}
