#include <iostream>

template<typename T> void foo(T&& arg)
{
}

int main()
{
	int n = 10;

	// 아래 ? 시험문제 입니다. 채워 보세요. 
	foo(n);  // T = ?  T&& = ?   foo( ? arg)
	foo(10); // T = ?  T&& = ?   foo( ? arg)
}




