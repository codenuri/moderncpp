// 7_생성자상속1 - 26page
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

	// #1. 생성자는 상속되지 않는다
	// #2. C++11 부터는 "상속해달라"고 요청할수 있습니다.
	using Base::Base;  // using 클래스이름::생성자이름
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}
