#include <iostream>
#include <string>

// git 에서 move06번 다시 복사해 오세요

// rule of 5, 3

// rule of 3 - C++98
// 클래스가 멤버로 포인터 등이 있고, 자원을 직접 관리하는 코드가 있다면
// 반드시 3개의 멤버 함수를 만들어야 합니다.
// => 소멸자, 복사 생성자, 대입연산자 

// rule of 5 - C++11 이후
// 이동 개념도 지원하려면 위 3개에 추가로 아래 2개를 만들어라
// => 이동 생성자, 이동 대입연산자



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

	Cat(Cat&& c) : name{ c.name }, age { c.age }
	{
		c.name = nullptr;
	}
	Cat& operator=(const Cat&& c)
	{
		if (&c == this)
			return *this;

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

	Cat c2 = c1;  // 초기화. 객체를 생성하면서 c1 넣기. 복사생성자 
	c2 = c1;	  // 대입, 생성된 객체에 c1 넣기. 대입연산자 호출
				  // c2.operator=(c1)

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




