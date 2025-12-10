#include <iostream>
#include <string>

// rule of 5, 3

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

	Cat(const Cat& c) : age{ c.age }
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	Cat& operator=(const Cat& c)
	{
		if (&c == this)
			return *this;

		age = c.age;
		delete[] name;

		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

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




