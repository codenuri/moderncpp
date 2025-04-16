#include <iostream>

void foo(int a) {}


// 핵심 정리
// 완벽한 전달 기술을 사용하려면 
// #1. 인자를 받을때는 T&& 로 받으세요
// #2. 받은 인자를 다른곳에 보낼때는 "std::forward<T>(arg)" 로 묶어서 보내 세요

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg)); 
}

int main()
{
	chronometry(foo, 10);


}
