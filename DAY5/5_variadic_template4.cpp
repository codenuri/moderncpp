#include <iostream>

// pack expansion

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	goo(args);	// error. pack ��ü�� �Լ� ���ڷ� ���ɼ� �����ϴ�.
				// pack �� Ǯ���� ������ �մϴ�.

	// pack expansion 
	// => "pack_name..."
	// => pack ���� ��� ��Ҹ� , �� ����ؼ� ������ �޶�� ��û
	// => �̸��� �ƴ϶� "pack�� ����ϴ� ����"... �� ����

	goo(args...);     // goo( E1, E2, E3 )

	goo((++args)...); // goo( ++E1, ++E2, ++E3 )
//	goo(++args...);   // () ��� �˴ϴ�.

//	goo( hoo(args...) ); // goo( hoo( E1, E2, E3)) �ε�.. hoo�� ���ڰ� �Ѱ� �̹Ƿ� error
						 
	goo( hoo(args)... ); // goo( hoo(E1), hoo(E2), hoo(E3))
						 // ok

}


int main()
{
	foo(1, 2, 3);
}
