#include <iostream>

// std::move() - 100 page

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

	Cat c2 = c1;	// 복사 생성자 호출

	Cat c3 = foo();	// 이동(move) 생성자 호출
	
	Cat c4 = static_cast<Cat&&>(c2); // 이동 생성자 호출
					// 즉, 임시객체 뿐 아니라
					// 어떠한 이름있는 객체도 
					// 캐스팅을 통해서 복사가 아닌 이동이 되게 할수 있다.
	
	Cat c5 = std::move(c3); // 이 표준함수가 하는일이
							// 위 처럼 캐스팅하는 일을 하고 있습니다.

	// std::move()
	// => 이 함수가 자원을 move 하는 것이 아닙니다.
	// => 단지, rvalue 로 캐스팅하는 일만 하고 있습니다.
	// => 캐스팅의 결과로 Cat 의 move 생성자가 호출되고
	// => move 생성자에서 자원이동..

}




