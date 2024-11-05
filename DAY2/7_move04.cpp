#include <iostream>
#include <cstring>

// shallow copy vs deep copy - 99page

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

		std::cout << "copy\n";
	}

	// 임시객체를 위한 복사생성자를 별도로 제공하자
	// => 임시객체는 rvalue 이므로 인자를 rvalue reference 로
	// => 아래 함수를 "move(이동) 생성자" 라고 합니다.
	Cat(Cat&& c) : age(c.age)
	{
		name = c.name;

		c.name = nullptr;	// 임시 객체가 자신의 자원을 포기
							// 이 작업을 하려면 
							// 임시객체를 "상수성 없이 가리킬수 있어야" 합니다.
							// 
							// 곧 파괴될 객체지만, 값을 변경할 필요가 있다는 것


		std::cout << "move\n";
	}

};

Cat foo()
{
	Cat c("yaong", 5);
	return c;
}
int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// 복사 생성자 호출

	Cat c3 = foo(); // 이 코드를 생각해 봅시다.
//  Cat c3 = 임시객체; // 이동생성자 호출
}
