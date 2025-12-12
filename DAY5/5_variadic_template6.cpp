#include <iostream>

// recursive 유사 기술

// #1. 모든 인자를 가변으로 하지말고 1번째 인자는 독립된 이름 사용

//void foo() {} // 재귀의 종료를 위해. C++11 시절 기술

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

	// 아래 if constexpr 은 C++17 부터 사용가능.
	if constexpr( sizeof...(args) > 0 )
		foo(args...); // value : 1,  args : 3.4, 'A'
					  // value : 3.4,   args : 'A'
					  // value : 'A'    args : 
					  // value : ??
}

int main()
{
	foo(1, 3.4, 'A'); 
}





