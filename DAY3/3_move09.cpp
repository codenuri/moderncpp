#include <iostream>
#include <cstring>
#include <string>

// rule of 0
// => 복사/이동 모두 만들지 않은 것이 best 이다!!!

// 자원을 직접 관리하지 말고, 자원 관리 객체에 의존해라!!
// char* => std::string
// int* => std::vector 또는 스마트 포인터...

// 자원관리는 직접하지 말고, 해당 자원을 관리하는 클래스를 사용하면
// => 이동과 복사를 모두 만들 필요 없다.
// => 컴파일러가 모두 지원하는 완벽한 클래스!!!


class Cat
{
//	char* name;
	std::string name;

	int   age;
public:
	Cat(const std::string& n, int a) : name(n), age(a)
	{
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




