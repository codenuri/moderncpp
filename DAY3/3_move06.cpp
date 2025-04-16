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


	// #2. primitive type 과 pointer 에 std::move 사용
	int n1 = 10;
	int n2 = std::move(n1);

	int* p1 = new int;
	int* p2 = std::move(p1);


	// #3. STL 의 대부분의 클래스는 std::move 를 지원한다.
	std::vector<int> v1 = { 1,2,3,4,5 };

	std::vector<int> v2 = std::move(v1);

	std::cout << v1.size() << std::endl;
}

