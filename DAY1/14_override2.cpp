#include <iostream>

template<typename T>
class Base
{
public:
	virtual void foo(const T* p)
	{
		std::cout << "Base foo\n";
	}
};

class Derived : public Base<int*>
{
public:
};
int main()
{
	Base<int*>* p = new Derived;
	d.foo(0); // "Derived foo" 나오게 해보세요. 
}