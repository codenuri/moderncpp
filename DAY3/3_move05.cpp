// std::move()�Ұ�
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
		std::cout << "����" << std::endl;
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	
	Cat c2 = c1;	// c1 �� lvalue,     ���� ������ ȣ��
	Cat c3 = foo();	// �ӽð�ü�� rvalue, �̵� ������ ȣ��

	Cat c4 = static_cast<Cat&&>(c2);
					// => lvalue �� c2 �� rvalue �� �����ؼ�
					// => �̵������ڸ� ȣ���ϰ� �Ѵ�.
					// => "c2" �� �� �̻� ������� �����Ƿ�
					//    �ڿ��� �̵��� ����� �ǹ�.

	Cat c5 = std::move(c3); // �� ǥ���Լ��� �ϴ�����
							// ���� ���� ĳ����

	// �ٽ� 
	// => "std::move()" �� �ڿ��� �̵��ϴ°� �ƴմϴ�!!!

	// 1. std::move �� ���� ���ڷ� ���޵� ��ü�� "rvalue �� ĳ����"�� �ϰ�
	// 2. ĳ���� ����� ��������ڰ� �ƴ� �̵������ڰ� ȣ��Ǵ� ���̰�
	// 3. Ŭ���� �ȿ� �̵� �����ڰ� �ڿ��� �̵��ϴ°�

	// �ᱹ, move �۾���
	// => Ŭ���� �����ڰ� "�̵������ڸ� ���� ����"
}


// �� �о߸� �н��Ҷ� "������"�� ����� �ٸ��� ������ ��찡 �����ϴ�.
// => �����Ϸ��� "���� �Ǵ� �̵� ������" ȣ���� �����ϴ� ����ȭ�� �ϱ� ����
// => "copy ellision �̶�� ����ȭ"


// g++ ����ϰ�, -fno-elide-constructors" ��� �ɼ��� ����ϸ�
// => "copy ellision" ���� ����� �ǹ� �Դϴ�.
// => g++ �ҽ��̸�.cpp -std=c++11 -fno-elide-constructors �� ����

