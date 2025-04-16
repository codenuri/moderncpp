#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];

		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
};

Cat foo()
{
	Cat c("yaong", 3);

	return c;
}

int main()
{
	Cat c = foo();	// 이 한줄에 대해서 생각해 봅시다.

	Cat c1("nabi", 2);
	Cat c2 = c1;
}