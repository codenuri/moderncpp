#include <iostream>

// recursive 유사 기술

// #1. 모든 인자를 가변으로 하지말고 1번째 인자는 독립된 이름 사용

//void foo() {} // 재귀의 종료를 위해. C++11 시절 기술

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int n = 0;
	++n;

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

// 위 코드는 재귀 호출 아닙니다.
// main() => foo(int, double, char) => foo(double, char) => foo(char)
// => 따라서, 크기가 큰 함수는 절대 사용하지 마세요
// => 간단하고 인라인 치환되어서 실제 함수는 사라지는 경우에 널리 사용




