// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

/*
// 인자 한개만 전달 가능
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f(std::forward<Ts>(args)); 
}
*/

// 인자의 갯수 제한 없음.
template<typename F, typename ... Ts>
decltype(auto) chronometry(F f, Ts&& ... args)
{
//	return f(std::forward<Ts>(args...)); // forward(e1, e2, e2) 이므로 error

	return f(std::forward<Ts>(args)...); 
		// f(std::forward<T1>(e1), std::forward<T2>(e2), std::forward<T3>(e3))
}
int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);
	std::cout << n << std::endl;
}
// 가변인자 템플릿은 언제 사용하나요 ??
// => 전형적으로 사용되는 패턴이 있습니다.
// => 대표적인 예가 "완벽한 전달"



