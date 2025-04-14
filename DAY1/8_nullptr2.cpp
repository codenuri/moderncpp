// 8_nullptr2
#include <iostream>

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)
{
	f(arg);
}



void foo(int* p) {}

int main()
{
	int n = 0;
	// #1. 아래 2줄 먼저 정확히 이해 하세요
	foo(0);	// ok
	foo(n);	// error

	// #2. 아래 코드를 생각해 보세요

	forward_parameter(foo, 0); // foo 에게 0을 전달해 달라
								// 즉, foo(0) 해달라는 것

}






