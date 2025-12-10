#include <iostream>
#include <string>


class Cat
{
	char* name;
	int   age;
	std::string address;

public:
	Cat(const char* n, int a, const std::string& addr = "unknown") 
		: age{ a }, address{ addr }
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age{ c.age }, address{addr}
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	Cat& operator=(const Cat& c)
	{
		if (&c == this)
			return *this;

		age = c.age;
		address = c.address;
		delete[] name;

		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}

	// move 생성자나 move 대입연산자를 직접 만들게 된다면
	// => 멤버 데이타중, 사용자 정의 타입이 있으면
	// => 옮길때 std::move() 로 옮겨야 한다.
	// => move 생성자에서는 멤버를 std::move() 로 옮겨라!

	Cat(Cat&& c) : name{ c.name }, age{ c.age }, address{ std::move(addr) }
	{
		c.name = nullptr;
	}
	Cat& operator=(const Cat&& c)
	{
		if (&c == this)
			return *this;

		age = c.age;
		address = std::move(c.address);
		delete[] name;

		name = c.name;
		c.name = nullptr;

		return *this;
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




