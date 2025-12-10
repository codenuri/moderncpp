#include <iostream>

// shallow copy vs deep copy

// 1. 컴파일러가 제공하는 복사 생성자는 
// => 모든 멤버 데이타를 그대로 복사 합니다.

// 2. 클래스내부에 포인터 멤버가 있으면
// => 컴파일러가 제공하는 복사 생성자는 얕은복사(shallow copy) 현상 발생!!

// 3. 해결책
// => 사용자가 복사 생성자를 직접 만들어야 합니다.
// => 보통, 깊은 복사(deep copy) 로 구현
// => 아래 구현 참고!
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

	// 복사 생성자 - 깊은 복사(deep copy)
	Cat(const Cat& c) : age{c.age}
	{
		// #1. 포인터가 아닌 멤버는 그대로 복사
		// age = c.age; // 이위치 보다는 초기화 리스트 권장

		// #2. 포인터의 경우는 메모리 할당후, 메모리 자체를 복사
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

};
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;  // 핵심
}
