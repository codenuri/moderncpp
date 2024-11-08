#include <iostream>

// 방법 #2. recursive 유사 코드

// 1. 1번째 인자는 독립된 변수 사용
// 2. 이후에 "recursive"

// 아래 코드는 "재귀적으로 함수의 생성" 이지, "재귀 호출"은 아닙니다.

// main => foo(인자3개) => foo(인자2개) => foo(인자1개)  호출한것



void foo() {}	// 재귀 종료

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

	// 아래 코드는 C++11.  재귀 종료를 위한 인자없는 foo() 필요
//	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()	=> 이 경우를 위해서 인자없는 함수 필요

	// 아래 코드는 C++17 이후 ( if constexpr 이 C++17)
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A');
}





