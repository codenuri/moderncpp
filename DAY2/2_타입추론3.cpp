#include <iostream>

// 규칙 2. 인자가 lvalue reference 일때( T& a)
// => 함수 인자가 가진 "reference" 속성만 제거하고 T의  타입을 결정
// => const, volatile 을 유지
template<typename T> void foo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);		// T = int,			a : int& 
	foo(c);		// T = const int	a : const int&
	foo(r);		// T = int			a : int& 
	foo(cr);	// T = const int	a : const int&
}
