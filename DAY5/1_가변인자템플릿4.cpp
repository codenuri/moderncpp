#include <iostream>

int  hoo(int a) { return -a; }
void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

	//	goo(args); // error. pack 을 직접 인자로 사용할수 없다.


	// pack expansion
	// => pack 안의 모든 요소를 , 를 사용해서 열거하는 기술
	// => "pack이름"...			=> e1, e2, e3
	// => "pack이름사용패턴"...	=> e1패턴, e2패턴, e3패턴

	goo(args...);		// goo(e1, e2, e3)

	goo((++args)...);	// goo(++e1, ++e2, ++e3)
						// ()없어도 됨 "goo(++args...)"

//	goo(hoo(args...));	// goo(hoo(e1, e2, e3)) 의미 인데 
						// hoo 는 인자가 한개인 함수 이므로 error

	goo(hoo(args)...);	// goo(hoo(e1), hoo(e2), hoo(e3))

	// 핵심 : 위 코드를 통해서 ... 의 위치와 차이점을 알아 두세요
}


int main()
{
	foo(1, 2, 3);
}
