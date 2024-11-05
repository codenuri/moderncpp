#include <iostream>
#include <string>

// move 계열함수 에서는 모든 멤버를 move로 옮겨라! - 102 page

class Cat
{
	char* name;
	int   age;
	std::string address;
public:
	Cat(const char* n, int a, const std::string& address) 
		: age(a), address(address)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }


	Cat(const Cat& c) : age(c.age), address(c.address)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}



	Cat(Cat&& c) noexcept 
//		: age(c.age), name(c.name), address(c.address) // bad. string의 복사 생성자
		: age(c.age), name(c.name), address(std::move(c.address)) // good. string의 move생성자
	{
		c.name = nullptr;
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





