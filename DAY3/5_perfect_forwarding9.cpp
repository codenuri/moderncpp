#include <iostream>

int& foo(int& a, double d, char c) { return a; }

void hoo() {}

// 완벽한 전달 추가
// 인자의 갯수 제한 없이
// => C++11 의 variadic template(5일차 주제)

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg) 
{
	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 0;

	chronometry(hoo);    // 인자가 없는 함수
	chronometry(foo, n, 3.4, 'A'); // 인자가 3개인 함수
}
