#include <iostream>
#include <type_traits>

// if constexpr 
// => 컴파일 시간 제어문
// => 조건식이 false 가 되면
// => 해당 부분은 "인스턴스화(template => 실제함수생성)" 에서 제외 해달라는 것

// if 문 은
// => 실행시간 제어문
// => 조건식이 false 라도, 실행만안되는 것이고
// => 인스턴스화에는 포함된다.


template<typename T> void printv(const T& v)
{
	// 현재 T=int 이므로 아래 코드는
	// if ( false )
	//if ( std::is_pointer_v<T> )
	if constexpr (std::is_pointer_v<T>)
	{
		std::cout << v << " : " << *v << std::endl;
	}
	else
	{
		std::cout << v << std::endl;
	}
}

int main()
{
	int n = 10;

	printv(n);
}

// 위 문제점이 아주 유명한 문제입니다
// 이 문제를 해결하는 방법은 총 4가지 입니다. 
// 모두 너무나도 유명한 기술들..

// 1. integral_constant - C++11
// 2. enable_if			- C++11
// 3. if constexpr		- C++17 ( 제일 쉬움, 위 코드)
// 4. concept 의 require 문법 - C++20 