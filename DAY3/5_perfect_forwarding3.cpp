#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10); // error.. 왜 안될까요 ?
}
