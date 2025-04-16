// git ���� move07 ������ ������

#include <iostream>
#include <cstring>

// rule of 5, 3

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

	// #1. ���� ������ - C++98
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	// #2. ���� ���Կ����� - C++98
	Cat& operator=(const Cat& c) 
	{
		if (&c == this)
			return *this;

		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}

	// #3. �̵������� - C++11
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
	}

	// #4. �̵� ���Կ����� - C++11
	Cat& operator=(Cat&& c)
	{
		if (&c == this)
			return *this;

		age = c.age;
		name = c.name;
		c.name = nullptr;

		return *this;
	}
};

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// #1. ���� ������ ȣ��
	c2 = c1;		// #2. ���� ������  c2.operator=(c1)

	Cat c3 = std::move(c1);	// #3. �̵� ������ ȣ��
	c3 = std::move(c2);		// #4. �̵� ���Կ����� ȣ��
}

// Ŭ���� �ȿ� ������ ����� �ְ� �ڿ��Ҵ� �ϴ� ���
// C++98 ���� �Ʒ� 3�� ��� �Լ��� �ݵ�� ������ �մϴ�.
// 
// => �Ҹ���, ���� ������, ���Կ�����
// => rule of 3

// C++11 ����, move �� �����Ϸ��� �� 3���� �߰��� 2���� ���������մϴ�.
// => �̵� ������, �̵� ���Կ�����
// => rule of 5




