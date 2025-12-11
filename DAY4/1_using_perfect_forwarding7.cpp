
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
	// 함수를 직접 호출시
	// => 인자를 보고 어느 함수인지 찾을수 있다.
	foo();
	foo(10);
	foo(10, 20);
 
	// 아래 처럼 사용하면 컴파일러는 foo 가 어떤 함수 인지 알수 없습니다.
//	chronometry(foo, 10); // error

	// 힌트를 주세요
	chronometry(static_cast<void(*)(int)>(foo), 10); // error
}









