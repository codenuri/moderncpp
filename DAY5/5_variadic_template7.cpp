// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// 가변인자 템플릿은 언제 사용하나요 ?
// => 전형적인 패턴이 있습니다.
// => 완벽한 전달에서 널리 사용

template<typename F, typename ... Ts>
decltype(auto) chronometry(F f, Ts&& ... args)
{
	return f( std::forward<Ts>(args)... ); 
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

