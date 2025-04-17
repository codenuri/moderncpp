// 9_완벽한전달_주의사항
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
 
	// 함수이름(주소)만 따로 인자로 전달할때는
	// => 동일 이름의 함수가 여러개 있다면 컴파일러가 찾을수 없습니다.
	// => 힌트를 제공하세요
//	chronometry(foo, 10); // error

	chronometry(static_cast<void(*)(int)>(foo), 10); // ok
}









