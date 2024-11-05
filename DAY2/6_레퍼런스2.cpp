#include <iostream>

// 90 page

// 아래 처럼 오버로딩 가능합니다.
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;

	foo(n); // n : lvalue
			// 1. int& 버전 호출,
			// 2. (1)이 없다면 const int& 버전 호출

	foo(10);// 10 : rvalue
			// 1. int&& 버전 호출
			// 2. (1)이 없다면 const int& 버전 호출

	// lvalue, rvalue 를 한개의 함수에서 처리
	// => const lvalue reference

	// lvalue, rvalue 를 다르게 처리
	// => lvalue reference 와
	// => rvalue reference 버전을 각각 만들면 됩니다.
}







