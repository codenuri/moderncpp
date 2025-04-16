#include <iostream>

int& foo(int& a) { return a; }


// 완벽한 전달 추가
// #1. 

template<typename F, typename T>
// auto chronometry(F f, T&& arg)  // return exp 의 결과가 참조일때
									// auto 는 참조를 제거하게 됩니다.
decltype(auto) chronometry(F f, T&& arg) // ok
{
	return f(std::forward<T>(arg));
}

int main()
{
	int n = 0;
	
	int& ret = chronometry(foo, n);

	ret = 100; // 결국 n = 100

	std::cout << n << std::endl; // 100 


}
