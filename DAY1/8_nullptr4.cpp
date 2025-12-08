// 8_nullptr2
#include <iostream>

void foo(int* p) {}

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg) // int arg = 0;	foo(arg) 이 에러
{									 // std::nullptr_t arg = nullptr; foo(arg) 은 ok
	f(arg);
}

int main()
{
	// foo 의 인자는 포인터
	// 0 을 사용하면
	foo(0); // 직접 전달은 ok
	
	forward_parameter(&foo, 0);  // error. 하지만 간접 전달은 모두 에러!

	forward_parameter(&foo, nullptr);
}








