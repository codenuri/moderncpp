// std::move()소개
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
		std::cout << "복사" << std::endl;
	}

	/*
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
	*/
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	

	// 핵심 : 이동 생성자가 없는 클래스의 객체에 대해서std::move() 를 사용했다면
	// 
	Cat c5 = std::move(c3);
			// static_cast<Cat&&>(c3);
			// lvalue => rvalue 변경한것. 
			// 복사생성자는 "lvalue, rvalue" 모두 받을수 있다.
			// 따라서 복사 생성자 호출

	// 결국
	// std::move() 사용시
	// 1. 이동생성자가 있다면 이동 생성자 사용
	// 2. 이동생성자가 없다면 복사 생성자 사용

	// 이동생성자가 없는 타입에 대해서도 "std::move()" 사용가능
	// => 단, 이동의 효과는 없다.

}


