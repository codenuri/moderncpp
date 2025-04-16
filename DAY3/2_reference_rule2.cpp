#include <iostream>

// 90 page
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;

	foo(n);		// 1. int& ȣ��..
				// 2. 1�� ���ٸ� const int& ȣ��
	
	foo(10);	// 1. int&& ȣ��
				// 2. int&& ������ ���ٸ� const int& ȣ��. 

	// lvalue, rvalue �� �ϳ��� �Լ����� ó���ϰ� �ʹ�.
	// => ���ڸ� "const &" �� �ϼ���

	// lvalue, rvalue �� �ٸ��� ����� �ʹ�.
	// => "& ������ && ����" �� �Լ��� ���� �����ϼ��� - move ����
}







