#include <iostream>

template<typename ... Ts> void foo(Ts ... args)
{
	// #1. parameter pack 용어 알아 두세요
	// Ts   : int, int, int   <= template parameter pack
	// args : 1, 2, 3		  <= function parameter pack

	// #2. pack 안에 요소 갯수 확인
	// => sizeof...(pack이름)
	std::cout << sizeof...(Ts)   << std::endl;
	std::cout << sizeof...(args) << std::endl;
}


int main()
{
	foo(1, 2, 3);
}
