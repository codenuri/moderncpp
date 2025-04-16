#include <iostream>

// 90 page
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;

	foo(n);		// 1. int& 호출..
				// 2. 1이 없다면 const int& 호출
	
	foo(10);	// 1. int&& 호출
				// 2. int&& 버전이 없다면 const int& 호출. 

	// lvalue, rvalue 를 하나의 함수에서 처리하고 싶다.
	// => 인자를 "const &" 로 하세요

	// lvalue, rvalue 를 다르게 만들고 싶다.
	// => "& 버전과 && 버전" 의 함수를 각각 제공하세요 - move 원리
}







