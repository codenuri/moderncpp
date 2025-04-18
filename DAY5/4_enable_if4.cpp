#include <iostream>
#include <type_traits>

// ���� C++�� "Ư�� Ÿ��" �� ���� �Լ� �����ε���
// ���� �մϴ�.
void foo(int)    {}
void foo(double) {}

// "Ÿ��"�� �ƴ� "Ư�� ������ �����ϴ� Ÿ�Ե�"�� ���� �����ε��� ������
// ���� ������� ?
//void goo(�����Լ����ִ�Ŭ������) {}
//void goo(�����Լ�������Ŭ������) {}

// std::enable_if_t<����, ��ȯŸ��>

template<typename T>
std::enable_if_t<std::is_polymorphic_v<T>, void>
goo(T a)
{
	std::cout << "�����Լ��� �ִ� ���\n";
}

template<typename T>
std::enable_if_t<!std::is_polymorphic_v<T>, void>
goo(T a)
{
	std::cout << "�����Լ��� ���� ���\n";
}

class A
{
	virtual void foo() {}
};
int main()
{
	A a;
	goo(a);
	goo(3); // int �� �����Լ� �����ϴ�.

}
