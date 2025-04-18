#include <iostream>

// pack expansion

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	goo(args);	// error. pack 자체는 함수 인자로 사용될수 없습니다.
				// pack 을 풀러서 보내야 합니다.

	// pack expansion 
	// => "pack_name..."
	// => pack 안의 모든 요소를 , 를 사용해서 열거해 달라는 요청
	// => 이름뿐 아니라 "pack을 사용하는 패턴"... 도 가능

	goo(args...);     // goo( E1, E2, E3 )

	goo((++args)...); // goo( ++E1, ++E2, ++E3 )
//	goo(++args...);   // () 없어도 됩니다.

//	goo( hoo(args...) ); // goo( hoo( E1, E2, E3)) 인데.. hoo는 인자가 한개 이므로 error
						 
	goo( hoo(args)... ); // goo( hoo(E1), hoo(E2), hoo(E3))
						 // ok

}


int main()
{
	foo(1, 2, 3);
}
