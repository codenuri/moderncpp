#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	std::cout << __FUNCSIG__ << std::endl;
}
int main()
{
	int n = 10;

	foo(n);  // T = int&, T&& = int& &&,  foo(int& arg)
	foo(10); // T = int,  T&& = int&&,    foo(int&& arg)
}




