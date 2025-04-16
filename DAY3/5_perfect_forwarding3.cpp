#include <iostream>

void hoo(int&& arg) {}


template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10);	// 왜 에러인지 생각해 보세요
							// 이유와 해결은 다음 소스에서
}
