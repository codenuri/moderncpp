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

	Cat(const Cat& c) : age{ c.age }
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
	// 위 복사 생성자가 : lvalue, rvalue 를 모두 받을수 있지만
	// 아래 버전이 있다면 : rvalue 의 경우는 아래 버전 사용
	// => 즉, rvalue 전용 복사 생성자
	
	// 임시객체(rvalue) 전용 복사 생성자
	Cat(Cat&& c) : name{ c.name }, age { c.age }
	{
		// 모든 멤버를 얕은 복사후 (초기화리스트 코드 참고)

		// rvalue 객체 c가 자원을 포기하게!!
		c.name = nullptr;

		// 위 코드가 되려면
		// => 임시객체를 "상수성 없이 받아서"
		// => 상태 변경을 할수 있어야 한다.

		// => 그래서 C++11 부터 상수성없이 임시객체를 가리킬수 있어야 한다.
	}
};





Cat foo()
{
	Cat c{ "yaong", 3 };
	return c;
}

int main()
{
	Cat c1{ "nabi", 2 };
	Cat c2 = c1;  

	Cat c3 = foo(); // 이 코드 실행시 메모리를 잘생각하세요
					// foo 의 반환값을 생각하세요.. 
}
