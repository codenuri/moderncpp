#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }


// 결론 : 완벽한 전달을 하려면
// #1. 인자를 받을때 "T&&" 로 받으세요
// #2. 다른 함수에 전달할때 "std::forward<T>(arg)" 로 묶어서 보내세요

// T&& : 결국 완벽한 전달을 하기 위해 만든 문법
// => 그래서, "forwarding reference" 라고 부르는 것

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg)); 
}


int main()
{
	int n = 10;

	chronometry(foo, 10); 

	chronometry(goo, n);  

	std::cout << n << std::endl;
}
