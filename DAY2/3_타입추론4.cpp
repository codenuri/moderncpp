#include <iostream>

// #2. 인자가 "참조" 타입 일때
// => 복사본이 아니라, 원본을 가리키겠다는 의미
// => "인자가 가진 reference 만 제거하고 T 의 타입 결정"
//    "const, volatile 은 유지"
template<typename T> void foo(T& a)
{
//	a = 100;
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);	// T = int			a = int&
	foo(c); // T = const int	a = const int& <== const 제거 안됨.
	foo(r);	// T = int			a = int&       <== reference 는제거
	foo(cr);// T = const int	a = const int&
}
