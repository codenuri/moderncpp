// 완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg) // int&& arg = 0
{
	f(std::forward<T>(arg));	// foo(arg)
}

void foo(int* p) {}

int main()
{
	foo(0); // ok

	chronometry(foo, 0); // foo(0) 해달라는 것
						 // 그런데, error

	chronometry(foo, nullptr); // ok

}

// 완벽한 전달 기술
// => 인자를 전달할때 중간층을 거쳐서 전달하는 것
// main ==> chronometry ==> foo

// 포인터 의미의 0 을 사용할수 없습니다.
// => nullptr 사용하세요








