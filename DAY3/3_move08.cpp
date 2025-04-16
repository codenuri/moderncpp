#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.

// ��Ģ #1. ����ڰ� "���� �迭(������, ���Կ�����) �Լ��� �̵� �迭�Լ�" �� ��� ������ ������
// => �����Ϸ��� ��� �����Ѵ�.

// => �����Ϸ��� �����ϴ� ���� �迭 �Լ������� ��� ����� ���� �ϰ�
// => �����Ϸ��� �����ϴ� �̵� �迭 �Լ������� ��� ����� �̵� �Ѵ�.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // ������

};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;			// o3.name = o1.name �ߴٴ� ��. ����
	Object o4 = std::move(o2);	// o4.name = std::move(o2.name) �ߴٴ°�

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}