#include <iostream>
#include <cstring>
#include <string>

// rule of 0
// => ����/�̵� ��� ������ ���� ���� best �̴�!!!

// �ڿ��� ���� �������� ����, �ڿ� ���� ��ü�� �����ض�!!
// char* => std::string
// int* => std::vector �Ǵ� ����Ʈ ������...

// �ڿ������� �������� ����, �ش� �ڿ��� �����ϴ� Ŭ������ ����ϸ�
// => �̵��� ���縦 ��� ���� �ʿ� ����.
// => �����Ϸ��� ��� �����ϴ� �Ϻ��� Ŭ����!!!


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




