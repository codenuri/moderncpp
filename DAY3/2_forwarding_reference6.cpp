#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	// #1. godbolt.org 에서 어셈블리 코드로 확인 - 권장
	// #2. 함수이름 출력 
	// vs  : __FUNCSIG__
	// g++ : __PRETTY_FUNCTION__

	std::cout << __FUNCSIG__ << std::endl;
}
int main()
{
	int n = 10;

	foo(n);  // T = int&
	foo(10); // T = int
}




