#include <iostream>
#include <string>


// ��Ģ #2. ����ڰ� ���� �迭�� ������ ���
// => �����Ϸ��� �̵� �迭 �Լ��� �������� �ʴ´�.
// => �̵��� �ʿ��� �ڵ尡 ������ "���� �迭(������)" ����Ѵ�.

// �̶�, �̵��迭�� �ʿ��ϸ� �����Ϸ����� "=default" �� ��û�ϸ� �ȴ�.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // ������

	Object(const Object& other) : name(other.name)
	{
		std::cout << "����ڰ� ���� ���� ������\n";
	}

	// "=default" ��û��, �̵������� �Ӿƴ϶� = �����ڵ� ���� �ϴ� ���� ����
	Object(Object&&) = default;

	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
};


int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				// ����ڰ� ���� ���� ������ ȣ��	
	Object o4 = std::move(o2);	// ����ڰ� ���� ���� ������ ȣ��
								// "=default"�� ��û�ߴٸ�, �����Ϸ� �����������

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl; 
}