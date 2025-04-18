#include <iostream>

// recursive ? - 233page

// 1. 1번째 인자는 별도의 이름있는 변수에 받는다.
// 2. 이후, 재귀 유사 기법으로 모든 인자 접근 

// 주의 : 진짜로 recursive 는 아닙니다
// => foo(3개인자) => foo(2개인자) => foo(1개인자)

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int n = 0;
	++n;

	std::cout << n << value << std::endl;

	if ( sizeof...(args) > 0 )
		foo(args...); // foo(3.4, 'A') => value : 3.4,  args : 'A'
					  // foo('A')	   => value : 'A'   args : ""
				
}

int main()
{
	foo(1, 3.4, 'A'); 
}





