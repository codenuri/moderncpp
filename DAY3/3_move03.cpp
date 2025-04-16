#include <iostream>

// move03 ~ 05 가 가장 중요한 소스

// shallow copy vs deep copy

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		// #1. 포인터가 아닌 멤버는 그대로 복사
//		age = c.age;	// 초기화 리스트에서 하는것을 권장

		// #2. 포인터는 메모리 할당후 메모리 자체를 복사
		name = new char[strlen(c.name) + 1];

		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
};
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; 
}