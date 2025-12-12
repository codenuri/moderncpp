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


	// #3. pack expansion - 핵심
	// "pack이름을 사용하는패턴"... => E1패턴, E2패턴, E3패턴

//	goo(args);	// error. pack 이름을 인자로 직접 사용안됨

	goo(args...); // ok. pack 의 모든 요소를 , 를 사용해서 열거
				  // goo(E1, E2, E3)

	goo((++args)...); // goo(++E1, ++E2, ++E3)


	goo(hoo(args...)); // goo(hoo(E1, E2, E3)) 의미.. 
						// 그런데 hoo() 는 인자 한개..
						// error

	goo(hoo(args)...); // ok.  goo(hoo(E1), hoo(E2), hoo(E3)) 

}



int main()
{
	foo(1, 2, 3);
}
