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

	d.foo();			// lvalue �� ��� �Լ� ȣ��

	Dialog{}.foo();		// rvalue �� ��� �Լ� ȣ��
}