#include <iostream>
// 85 page


struct Base
{
	int value{ 10 };
};
struct Derived : public Base
{
	int value{ 20 };
};
int main()
{
	Derived d;

	std::cout << d.value << std::endl;  // Derived �� �߰��� value 20

	// ��� Ŭ����(Base)���� ��ӹ��� value �����Ϸ��� ĳ���� �ʿ�
	std::cout << static_cast<Base>(d).value << std::endl; // 10

}

