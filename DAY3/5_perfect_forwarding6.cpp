#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{

//	f(static_cast<T&&>(arg));	// 이렇게 사용해도 됩니다.
								// 정확한 코드 입니다.

	// 그런데, C++ 표준에서는 위와 동일한 캐스팅을 수행하는
	// std::forward 를 제공합니다.

	f(std::forward<T>(arg)); // 위 코드와 완전히 동일
							 // 단, T&& 가 아닌 T 로 전달해야 합니다.
							 // 내부적으로 && 를 붙여서 캐스팅합니다.
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	

	chronometry(goo, n);	

}
