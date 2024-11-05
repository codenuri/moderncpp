#include <iostream>
// 규칙 1. 인자가 값타입(T a) 일때
// => 함수 인자가 가진 "const, volatile, reference" 속성을 모두 제거후 타입결정
template<typename T> void foo(T a)
{
	a = 100;
}
int main()
{
	// 사용자가 타입을 전달하면
	// => 무조건 사용자가 전달한 타입 사용
	foo<int>(3.4);

	// 사용자가 타입을 전달하지 않으면
	// => 함수 인자로 타입 결정
	foo(10); // T = int
	foo(3.4);// T = double

	//---------------------------------------------
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n);		// T = int
	foo(c);		// T = int
	foo(r);		// T = int
	foo(cr);	// T = int
}
