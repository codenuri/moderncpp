#include <iostream>

// recursive ? - 233page

// 1. 1��° ���ڴ� ������ �̸��ִ� ������ �޴´�.

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





