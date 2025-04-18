// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

// void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3); // 1. int ���� ���  => exactly matching
			// 2. T ���� ����ؼ� foo(int) �Լ� ����
			// 3. ... ���

	// ��ó�� �����̸��� �Լ��� ������ ������ �Լ� ã�� ������
	// "overloading resolution" �̶�� �մϴ�
	// => ���� �����մϴ�. (foo(double) � ��� ����ϸ�)
}