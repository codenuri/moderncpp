#include <iostream>
#include <string>


// ��Ģ #2. ����ڰ� �̵� �迭�� ������ ���
// => �����Ϸ��� ���� �迭�� ������ �ʴ´�.
// => ���簡 �ʿ��� �ڵ尡 ������ "����"
//    ���簡 �ʿ� �Ҷ� "�̵�"�� ����Ҽ� ����.

// �̶�, ����迭�� �ʿ��ϸ� �����Ϸ����� "=default" �� ��û�ϸ� �ȴ�.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // ������

	Object(Object&& other) : name(std::move(other.name) )
	{
		std::cout << "����ڰ� ���� �̵� ������\n";
	}
	
	// �̵������ڸ� ������ �������� ����Ʈ ��û
	Object(const Object&) = default;
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				
	Object o4 = std::move(o2);	

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl;
}