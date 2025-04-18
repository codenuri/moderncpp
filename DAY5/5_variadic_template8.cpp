#include <iostream>

// recursive ? - 233page

// 1. 1번째 인자는 별도의 이름있는 변수에 받는다.

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

	if ( sizeof...(args) > 0 )
		foo(args...); // foo(3.4, 'A') => value : 3.4,  args : 'A'
					  // foo('A')	   => value : 'A'   args : ""
				
}

int main()
{
	foo(1, 3.4, 'A'); 
}





