// 5_SFINAE - 
#include <iostream>

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

// void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3); // 1. foo(int) 호출, exactly matching
			// 2. foo(T) 를 사용해서 foo(int) 생성. 
			// 3. foo(...)

	// 위순서 외워 두세요.
}
