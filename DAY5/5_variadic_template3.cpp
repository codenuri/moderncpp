#include <iostream>

// parameter pack, sizeof...

template<typename ... Types> void foo(Types ... args)
{
	// #1. "parameter pack" 이라는 용어 알아 두세요
	// 
	// Types : int, int, int	=> template parameter pack
	// args  : 1, 2, 3			=> function parameter pack


	// #2. sizeof... : pack 안에 있는 요소의 갯수 조사

	std::cout << sizeof...(Types) << std::endl; // 3
	std::cout << sizeof...(args)  << std::endl; // 3
}





int main()
{
	foo(1, 2, 3); // void foo(int, int, int) 함수 생성됩니다.
}