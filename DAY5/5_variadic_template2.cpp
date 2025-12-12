#include <iostream>

// 가변인자 함수 템플릿

template<typename ... Types> 
void foo(Types ... args)
{

}

int main()
{
	foo(1, 3.4, 'A');	// Types : int, double, char
						// args  : 1,   3.4,    'A'

	foo(1, 3.4); // Types : int, double
				 // args  : 1,   3.4
	
}

// 가변인자 함수 템플릿의 의미
// foo(T arg)      : 인자가 한개인 함수를 다양한 타입에 대해 생성가능
// foo(T ... args) : 모든 형태의 함수를 만들수 있다.
//					 인자 갯수, 타입에 상관없이

// 위 코드 godbolt.org 에 넣으세요
