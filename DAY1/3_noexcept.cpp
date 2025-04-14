// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// C++11 noexcept �� �뵵
// 1. �Լ��� ���ܰ� ������ "����" �ϰų�
// 2. �Լ��� ���ܰ� ������ "ǥ��" �ϱ� ���ؼ� ���

// �����Ϸ��� �Լ� ȣ���� ��ȿ���� �����Ҷ�
// => �Լ� ������ �����Ҽ��� �����ϴ�.
//    (�Լ� ���� ���� ȣ�� ���� ���θ� �Ǵ��ϹǷ�)

// => ����, ��� �Լ��� ���� ���ɼ��� �ֽ��ϴ�.

// => ���ܰ� ������ �����Ҽ� �ִٸ�, �Լ� �����ڰ�
//    �˷� �־�� �մϴ�.

void foo() noexcept    // �Լ� �� ���ܰ� ������ �˸��� ���
{
}
void goo()	
{
}

int main()
{
	// noexcept( �Լ� ȣ�� ǥ���� ) : ǥ���� ���� ȣ��������
	//								 ���� ���ɼ��� ������ true
	// ���� : �Լ� ����ڿ� noexcept �� ǥ��Ǿ� �ִ��� �����ϴ°�					
	bool b1 = noexcept(foo());	// true
	bool b2 = noexcept(goo());	// false

	std::cout << std::boolalpha; // 1, 0 �� �ƴ� true, false �� �ش޶�
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}




