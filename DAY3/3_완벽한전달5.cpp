#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}


template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// 아래 캐스팅은 rvalue 캐스팅입니다. ( T&& 가 아닌 int&& 이므로)
//	static_cast<int&&>(arg);


	// 아래 캐스팅은 rvalue 캐스팅이 아닙니다.
	// chronometry 의 2번째 인자로
	// rvalue(10) 을 전달하면 (받으면서 arg 가 lvalue로 된것을 다시) rvalue 캐스팅
	// lvalue(n)  을 전달하면 (필요없는 캐스팅이지만)               lvalue 캐스팅
//	static_cast<T&&>(arg);


//	f(static_cast<T&&>(arg)); // 이 코드도 정확한 문제 없는 코드입니다.
	f(std::forward<T>(arg));  // std::forward<T>() 가 하는 일이
							  // 위 코드와 동일(캐스팅)합니다.
							  // 이 경우는 T&& 가 아닌 T 입니다.
}

int main()
{
	int n = 10;

	chronometry(foo, 10);	

	chronometry(goo, n);	
}





