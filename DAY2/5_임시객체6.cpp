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
	std::cout << static_cast<Base&>(d).value << std::endl;

	// static_cast<Base>(d) : d�� �����ؼ� Base Ÿ���� �ӽð�ü�����
	// static_cast<Base&>(d) : d�� Base Ÿ�� ó�� ������ �޶�°�


	static_cast<Base>(d).value = 30;	// error. 
										// �ӽð�ü.value = 30
	static_cast<Base&>(d).value = 30;	// ok
										// d��Baseó�������ؼ�.value = 30
}
// �ᱹ �ӽð�ü��
// 1. ����ڰ� �ǵ������� ����⵵ �մϴ�.
//    draw_line( Point{0,0}, Point{1,1} )

// 2. ����ڰ� �ۼ��� �ڵ� ������ �����Ǳ⵵ �մϴ�
// => ���� ��ȯ�ϴ� �Լ�  : Point foo() { return pt;}
// => ��Ÿ������ ĳ����   : static_cast<Base>(d)

// ���� �ӽð�ü�� �����Ǵ��� �ƴ� ���� �߿��մϴ�.!!!

