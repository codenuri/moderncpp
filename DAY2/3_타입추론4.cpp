#include <iostream>

// 규칙 #2. 인자가 참조 타입 일때
// => 함수 인자의 reference 속성만 제거하고 타입 결정
// => const, volatile 속성은 유지 
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

	// T 와 a 의 타입을 각각 구별해서 생각해야 합니다.
	foo(n);		// T = int		a = int&
	foo(c);		// T = int	    a = int& 로 결정하면 int& a = c 인데. error
				// T = const    a = const int& 로 결정!! <= 위와 같은 이유로!
	
	foo(r);		// T = int			a = int&
	foo(cr);	// T = const int	a = const int& 	
}