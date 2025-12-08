#include <iostream>

template<typename T>
class Base
{
public:
	virtual void foo(const T p)
	{
		std::cout << "Base foo\n";
	}
};

class Derived : public Base<int*>
{
public:
	// foo() 가상함수 재정의 하세요. - override 키워드 사용하지 말고 해보세요
};
int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" 나오게 해보세요. 
}