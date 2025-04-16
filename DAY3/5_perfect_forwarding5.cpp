#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg));  // 필요없는 캐스팅인데..
								// 있어도 됩니다.
								// 컴파일 시에 제거 됩니다.
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

// 아래 템플릿(T&&) 이 위 2개의 함수를 자동생성합니다.
// => int 뿐 아니라 모든 타입의 인자에도 사용가능합니다.
template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}


int main()
{
	int n = 0;
	chronometry(foo, 10);
	chronometry(goo, n);
	chronometry(hoo, 10);
}
