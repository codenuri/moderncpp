#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
// #1. int& 와 int&& 버전이 따로 있어야 합니다.
// #2. 아래 코드는 단 한가지의 문제가 있습니다. hoo() 를 생각해 보세요

void hoo(int&& arg) {}

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
	hoo(10); // ok
	chronometry(hoo, 10); // error
						  // 원인과 해결책은 다음소스에서.. 

	int n = 10;
	chrometry(foo, 10); 
	chrometry(goo, n);  

	std::cout << n << std::endl;
}





