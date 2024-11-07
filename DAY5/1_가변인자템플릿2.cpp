#include <iostream>

// 가변인자 함수 템플릿
// #1. ... 위치 잘 알아두세요
// #2. 의미
// 인자가 한개인 함수 템플릿 : 인자가 한개인 함수 생성
// 가변 인자 함수 템플릿     : 인자의 갯수에 상관없이 함수 생성가능
//							 godbolt.org 사용해서, 생성된 함수 확인!!
template<typename T> 
void goo(T arg)
{
}
goo(3);    // goo(int) 생성
goo(3.4);  // goo(double) 생성

template<typename ... Ts> 
void foo(Ts ... args)
{
}

int main()
{
	foo(1);
	foo(1, 3.4);
	foo(1, 3.4, 'A');	// Ts   : int, double, char
						// args : 1, 3.4, 'A'
}
