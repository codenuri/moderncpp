#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void f1() {}
void f3(int a, double d, int& r) {}

// 인자가 한개가 아니라, 여러개를 forwarding 하려면
// => 가변인자 template 기술 - 금요일에 배우는 주제
template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)
{
	f(std::forward<T>(arg)... );
}

int main()
{
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n);

	chronometry(f1);
	chronometry(f3, 10, 3.4, n);

	std::cout << n << std::endl;
}
