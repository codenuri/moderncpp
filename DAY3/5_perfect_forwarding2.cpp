#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// 1. call by reference �� �ؾ� �ϰ�
// 2. lvalue reference, rvalue reference ������ ���� �����ؾ� �Ѵ�.

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	chronometry(foo, 10);	
	chronometry(goo, n);	

	std::cout << n << std::endl;
}
