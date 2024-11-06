#include <iostream>

// rule of 5, 3

// 생성자에서 자원을 할당하면
// C++98     : 소멸자, 복사생성자, 대입연산자 를 만들어야 합니다 - rule of 3
// C++11이후 : 소멸자, 복사생성자, 대입연산자, 이동 생성자, 이동대입연산자필요
//		     => rule of 5 라고 합니다.


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
	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		age = c.age;

		delete[] name;

		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	
		return *this;
	}
	
	Cat(Cat&& c) noexcept : age(c.age), name(c.name)
	{
		c.name = nullptr;
	}

	Cat& operator=(Cat&& c) noexcept
	{
		if (&c == this) return *this;

		age = c.age;

		delete[] name;

		name = c.name;
		c.name = nullptr;

		return *this;
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	// 복사 생성자
	c2 = c1;		// 대입 연산자

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




