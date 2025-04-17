#include <iostream>

class Dialog
{
public:
	void foo() &  { std::cout << "foo &\n"; }
	void foo() && { std::cout << "foo &&\n"; }
};

int main()
{
	Dialog d;

	d.foo();			// lvalue 로 멤버 함수 호출

	Dialog{}.foo();		// rvalue 로 멤버 함수 호출
}