#include <iostream>
#include <string>

// rule of 0
// => 자원을 직접 관리하지 않고
// => 자원 관리 클래스(char* => std::string, int* => std::vector)
//    를 사용하면 
// => 복사, move 계열은 모두 만들필요 없다. 

class Cat
{
	std::string name;
	int   age;
	std::string address;
public:
	Cat(const std::string& n, int a, const std::string& address)
		: name(n), age(a), address(address)
	{
	}
};


int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;
	c2 = c1;

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}





