#include <iostream>

int& goo(int& a) { a = 100; return a; }

// 반환값도 완벽하게 반환
// auto a = expresion; 에서 expression 이 참조라면 참조 제거됨
// decltype(auto) a = expression; 은 참조 유지

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 10;

	int& ret = chronometry(goo, n);
	ret = 300; // n = 300

	std::cout << n << std::endl;
}
