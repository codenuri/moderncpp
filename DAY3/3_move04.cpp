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
	}

	// 임시객체(rvalue) 전용 "복사 생성자"
	// => 위 복사 생성자가 "lvalue, rvalue" 를 모두 받을수있지만
	// => 아래와 같이 rvalue 전용 버전을 만들면
	// => 임시객체(rvalue) 의 경우 아래 버전 사용
	// => 아래 멤버 함수를 "이동생성자(move constructor)" 라고 합니다.
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
	//	name = c.name;

		c.name = nullptr; // 자원을 포기하게 합니다.
						  // 임시객체 소멸자가 delete 0 하게 되는데
						  // 0번지를 delete 하는 것은 아무일도 하지 않는것!!

						  // 이작업을 하려면 "임시객체(rvalue)" 를
						  // "상수성없이(non-const) 가르켜야 합니다."
	}


};

Cat foo()
{
	Cat c("yaong", 3);

	return c;
}



int main()
{
	Cat c = foo();	// 이 한줄에 대해서 생각해 봅시다.

	Cat c1("nabi", 2);
	Cat c2 = c1;
}