#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}

int main()
{
	int n = 0;
	chronometry(foo, 10);
	chronometry(goo, n);
	chronometry(hoo, 10);
}
