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

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	
	Cat c2 = c1;	// c1 은 lvalue,     복사 생성자 호출
	Cat c3 = foo();	// 임시객체는 rvalue, 이동 생성자 호출

	Cat c4 = static_cast<Cat&&>(c2);
					// => lvalue 인 c2 를 rvalue 로 변경해서
					// => 이동생성자를 호출하게 한다.
					// => "c2" 를 더 이상 사용하지 않으므로
					//    자원을 이동해 가라는 의미.

	Cat c5 = std::move(c3); // 이 표준함수가 하는일이
							// 위와 같은 캐스팅

	// 핵심 
	// => "std::move()" 가 자원을 이동하는것 아닙니다!!!

	// 1. std::move 는 단지 인자로 전달된 객체를 "rvalue 로 캐스팅"만 하고
	// 2. 캐스팅 결과로 이동생성자가 호출되는 것이고
	// 3. 이동 생성자가 자원을 이동하는것

	// 결국, move 작업은
	// => 클래스 설계자가 "이동생성자를 만들어서 제공"
}




