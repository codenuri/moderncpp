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
	

	// rvalue 전용의 복사 생성자는
	// => 결국 자원의 복사가 아닌 이동입니다.
	// => 이동생성자(move constructor) 라고 부릅니다.
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

	Cat c2 = c1;	// copy constructor
	Cat c3 = foo(); // move constructor

	Cat c4 = static_cast<Cat&&>(c2);	// 강제로 rvalue 로 캐스팅해서
										// move constructor 를 호출하게 한다.
	Cat c5 = std::move(c3);
				// 이 함수가 하는 일이 "위와 동일하게 캐스팅" 하는 일
}

// 핵심 : std::move() 가 자원이동하는 것 아닙니다!!!

// 1. Cat 개발자가 복사 생성자/이동 생성자 를 모두 제공하고
// 2. std::move() 사용시, 단지 rvalue 로 캐스팅 되고
// 3. 캐스팅 결과로 복사가 아닌 이동 생성자가 호출된것

// 즉, 이동의 기능은
// => 클래스 설계자가 하는 것
// std::string s2 = std::move(s1); // string 클래스 설계자가 만든 move 생성자 
//									// 에서 자원이동. 


