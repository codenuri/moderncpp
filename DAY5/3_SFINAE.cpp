// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

// void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3); // 1. int 버전 사용  => exactly matching
			// 2. T 버전 사용해서 foo(int) 함수 생성
			// 3. ... 사용

	// 위처럼 동일이름의 함수가 여러개 있을때 함수 찾는 순서를
	// "overloading resolution" 이라고 합니다
	// => 아주 복잡합니다. (foo(double) 등도 모두 고려하면)
}