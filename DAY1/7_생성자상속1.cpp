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
	// "생성자는 상속 되지 않는다" 라는 문법이 있습니다.
	// C++11 부터 생성자 상속을 가능하게 할수 있습니다.
	using Base::Base;    // using 클래스이름::함수이름

	// 위문법이 없다면 아래 처럼해야 합니다.
//	Derived() {}
//	Derived(int n) : Base(n) {}
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}
