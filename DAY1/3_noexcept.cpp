// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// C++11 noexcept �� �뵵
// 1. �Լ��� ���ܰ� ������ "����" �ϰų�
// 2. �Լ��� ���ܰ� ������ "ǥ��" �ϱ� ���ؼ� ���

void foo() 
{
}
void goo()
{
}

int main()
{
	// noexcept( �Լ� ȣ�� ǥ���� ) : ǥ���� ���� ȣ��������
	//								 ���� ���ɼ��� ������ true
	bool b1 = noexcept(foo());
	bool b2 = noexcept(goo());

	std::cout << std::boolalpha; // 1, 0 �� �ƴ� true, false �� �ش޶�
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}




