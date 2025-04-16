// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding
// => 전달 받은 인자를 다른 함수 에 보내는 것

// perfect forwarding (완벽한 전달)
// => 전달 받은 인자를 어떠한 변화도 없이 그대로 전달하는 것


// 성능측정하는 함수를 만들어 봅시다.
template<typename F, typename T>
void chronometry(F f, const T& arg)
{
	// 현재시간기록
	f(arg);
	// 수행시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10);	// foo(10);
	chronometry(goo, n);	// goo(n);

	std::cout << n << std::endl;
}
