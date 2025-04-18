#include <iostream>

// 가변인자 템플릿은 언제 사용하나요 ??
// => 필요한 전형적인 경우가 있습니다. 그때만 사용하면 됩니다.

// #1. 완벽한 전달
// #2. tuple 같은 도구 만들때.. 



void foo(int a, int b, int& c) { c = 100; }

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
//	return f( std::forward<T>(arg...)); // std::forward 에 3개인자 모두 전달
	return f(std::forward<T>(arg)...); 
			// f( std::forward<T1>(E1), 
			//	  std::forward<T2>(E2), std::forward<T3>(E3))
}

int main()
{
	int n = 10;

	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

