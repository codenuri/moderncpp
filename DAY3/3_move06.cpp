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
		std::cout << "����" << std::endl;
	}

	/*
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}
	*/
};

int main()
{
	Cat c1("nabi", 2);

	// std::move ���� �˾� �Ѱ�

	// #1. "move �����ڰ� ���� Ÿ��"�� ���ؼ� std::move �� ����ߴ�.
	Cat c2 = std::move(c1);


	// #2. primitive type �� pointer �� std::move ���
	int n1 = 10;
	int n2 = std::move(n1);

	int* p1 = new int;
	int* p2 = std::move(p1);


	// #3. STL �� ��κ��� Ŭ������ std::move �� �����Ѵ�.
	std::vector<int> v1 = { 1,2,3,4,5 };

	std::vector<int> v2 = std::move(v1);

	std::cout << v1.size() << std::endl;
}

