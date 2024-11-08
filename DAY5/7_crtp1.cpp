// 7_crtp1
#include <iostream>

template<typename T>
class Base
{
public:
	void foo()
	{
		// 여기서 파생클래스 이름을 사용할수 있을까 ?
		T obj; // Derived obj

		std::cout << typeid(obj).name() << std::endl;
	}
};

class Derived : public Base< Derived >
{
};
int main()
{
	Derived d;
	d.foo();
}