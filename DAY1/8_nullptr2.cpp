// 8_nullptr2
#include <iostream>

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)	// int arg = 0; 
{
	f(arg);	// arg 가 int 였다면 foo(arg) 이므로 error
}



void foo(int* p) {}

int main()
{
	int n = 0;
	// #1. 아래 2줄 먼저 정확히 이해 하세요
	foo(0);	// ok
	foo(n);	// error

	// #2. 아래 코드를 생각해 보세요

///	forward_parameter(foo, 0); // foo 에게 0을 전달해 달라
								// 즉, foo(0) 해달라는 것
								// 하지만 지금은 에러.
	forward_parameter(foo, nullptr); // ok!!!

	// nullptr 을 만든이유
	// => C++11 부터 "인자를 forward"하는 기술을 널리 사용하는데
	// => 0 사용시 위처럼 에러가 발생할수 있다.
	// => nullptr 사용시 문제 없음. 
}






