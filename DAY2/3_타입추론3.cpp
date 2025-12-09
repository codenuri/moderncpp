#include <iostream>

// 추론 규칙#1. 인자가 "값 타입" 일때 
// => 복사본이 생성된다.
// => 메모리 속성이 아닌 값으로만 타입 추론
// => "인자가 가진 const, volatile, reference" 속성을 제거후 타입 결정
template<typename T> void foo(T a)
{
	a = 100;
	std::cout << __FUNCSIG__ << std::endl;
}
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T = int
	foo(c);  // T = int 
	foo(r);  // T = int
	foo(cr); // T = int
}
