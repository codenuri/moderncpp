// move06, move07 은 기존 코드 지우고
// git 에 있는 코드 복사해 오세요




#include <iostream>
#include <string>
#include <vector>
#include <cstring>

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

	// std::move 관련 알아 둘것

	// #1. "move 생성자가 없는 타입"에 대해서 std::move 를 사용했다.
	Cat c2 = std::move(c1);
				// static_cast<Cat&&>(c1) 
				// 즉, c1 을 rvalue 로 해석해달라고 컴파일러에 요청한것
				// 복사 생성자는 lvalue, rvalue 모두 받을수 있다
				// => "복사 생성자 사용"


	// #2. primitive type 과 pointer 에 std::move 사용
	// => 아무일도 일어나지 않는다.
	// => 에러도 아니다.
	int n1 = 10;
	int n2 = std::move(n1); // int n2 = n1 과 동일 

	int* p1 = new int;
	int* p2 = std::move(p1); // move 효과 없음
							 // int* p2 = p1 과 동일!


	// #3. STL 의 대부분의 클래스는 std::move 를 지원한다.
	std::vector<int> v1 = { 1,2,3,4,5 };

	std::vector<int> v2 = std::move(v1); // 자원(버퍼)이동

	std::cout << v1.size() << std::endl; // 0
}

//-----------------------------------------
Cat foo()
{
	Cat c("nabi", 10);

	return c;		// A
}

Cat ret = foo();	// B. 이 한줄에 실행결과를 완벽히 이해해 봅시다.
