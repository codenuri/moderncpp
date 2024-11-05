#include <iostream>

// 규칙 2. 인자가 lvalue reference 일때( T& a)
// => 함수 인자가 가진 "reference" 속성만 제거하고 T의  타입을 결정
// => const, volatile 을 유지
template<typename T> void foo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;

	// 주의 : 절대로 RTTI 기술로 타입을 조사하지 마세요
	// => C++ RTTI 기술은 const, reference 를 출력하지 않습니다.
	// => 참고, C++26 에서 reflection 라이브러리가 추가될예정
	std::cout << typeid(T).name() << std::endl;
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
