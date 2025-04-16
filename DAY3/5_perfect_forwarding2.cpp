#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// 1. call by reference 로 해야 하고
// 2. lvalue reference, rvalue reference 버전을 각각 제공해야 한다.

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
