#include <iostream>

int hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// #1. 용어
	// Types : int, int, int   => template parameter pack
	// args  : 1,   2,   3     => function parameter pack

	// #2. pack 안에 있는 갯수 구하기
	std::cout << sizeof...(Types) << std::endl;
	std::cout << sizeof...(args ) << std::endl;

}


int main()
{
	foo(1, 2, 3);
}
