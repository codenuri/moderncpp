// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// 핵심
// 1. 인자의 복사본을 만들면 안된다 - 참조
// 2. 상수성 등도 추가되면 안된다

// => int& 와 int&& 버전을 각각 제공
// => 그런데, 이코드는 현재 코드는 문제가 없지만 한개의 문제점이 있습니다.(다음예제)
template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);		
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
