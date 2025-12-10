#include <iostream>

// 90 page
// 동일 이름의 함수를 아래 처럼 overloading 가능합니다.
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;

	foo(n); // n 은 lvalue
			// 1. int& 호출 - 우선권
			// 2. (1) 이 없다면 const int& 호출
	
	foo(10); // 10 은 rvalue
			 // 1. int&& 가 호출, 우선권
			 // 2. (1) 이 없다면 const int& 호출

	// lvalue, rvalue 를 동시에 한개의 함수에서 처리
	// => 인자로 const int&

	// lvalue, rvalue 를 다르게 구현
	// => int&, int&& 버전을 각각 만들어라!
} 







