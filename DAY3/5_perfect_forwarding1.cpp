// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// ���������ϴ� �Լ��� ����� ���ô�.
template<typename F, typename T>
void chronometry(F f, T arg)
{
	// ����ð����
	f(arg);
	// ����ð� ���
}
int main()
{
	int n = 10;

	chronometry(foo, 10);	// foo(10);
	chronometry(goo, n);	// goo(n);

	std::cout << n << std::endl;
}
