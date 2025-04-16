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

	// �ӽð�ü(rvalue) ���� "���� ������"
	// => �� ���� �����ڰ� "lvalue, rvalue" �� ��� ������������
	// => �Ʒ��� ���� rvalue ���� ������ �����
	// => �ӽð�ü(rvalue) �� ��� �Ʒ� ���� ���
	// => �Ʒ� ��� �Լ��� "�̵�������(move constructor)" ��� �մϴ�.
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
	//	name = c.name;

		c.name = nullptr; // �ڿ��� �����ϰ� �մϴ�.
						  // �ӽð�ü �Ҹ��ڰ� delete 0 �ϰ� �Ǵµ�
						  // 0������ delete �ϴ� ���� �ƹ��ϵ� ���� �ʴ°�!!

						  // ���۾��� �Ϸ��� "�ӽð�ü(rvalue)" ��
						  // "���������(non-const) �����Ѿ� �մϴ�."
	}


};

Cat foo()
{
	Cat c("yaong", 3);

	return c;
}



int main()
{
	Cat c = foo();	// �� ���ٿ� ���ؼ� ������ ���ô�.

	Cat c1("nabi", 2);
	Cat c2 = c1;
}