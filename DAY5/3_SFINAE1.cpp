// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }


int main()
{
	foo(3); // 1. foo(int) 호출 - exactly matching
			// 2. foo(T) 호출 - template 으로 int 버전 생성가능
			// 3. foo(...) 호출
	// overloading resolution
	// => 동일 이름의 함수가 여러개 있을때 함수 찾는 규칙
}
