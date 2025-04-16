// git 에서 move07 복사해 오세요

#include <iostream>
#include <cstring>

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

	// #1. 복사 생성자 - C++98
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	// #2. 복사 대입연산자 - C++98
	Cat& operator=(const Cat& c) 
	{
		if (&c == this)
			return *this;

		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}

	// #3. 이동생성자 - C++11
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
	}

	// #4. 이동 대입연산자 - C++11
	Cat& operator=(Cat&& c)
	{
		if (&c == this)
			return *this;

		age = c.age;
		name = c.name;
		c.name = nullptr;

		return *this;
	}
};

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// #1. 복사 생성자 호출
	c2 = c1;		// #2. 대입 연산자  c2.operator=(c1)

	Cat c3 = std::move(c1);	// #3. 이동 생성자 호출
	c3 = std::move(c2);		// #4. 이동 대입연산자 호출
}

// 클래스 안에 포인터 멤버가 있고 자원할당 하는 경우
// C++98 시절 아래 3개 멤버 함수를 반드시 만들어야 합니다.
// 
// => 소멸자, 복사 생성자, 대입연산자
// => rule of 3

// C++11 이후, move 를 지원하려면 위 3개에 추가로 2개를 더만들어야합니다.
// => 이동 생성자, 이동 대입연산자
// => rule of 5




