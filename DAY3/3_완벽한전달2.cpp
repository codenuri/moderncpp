#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
//#1. int& 와 int&& 버전이 따로 있어야 합니다.
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
	chrometry(foo, 10); 
	chrometry(goo, n);  

	std::cout << n << std::endl;
}





