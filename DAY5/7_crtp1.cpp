// 7_crtp1
#include <iostream>

class Base
{
public:
	void foo()
	{
		// 여기서 파생클래스 이름을 사용할수 있을까 ?
	}
};
class Derived : public Base
{
};
int main()
{
	Derived d;
	d.foo();
}