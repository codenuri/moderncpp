// 8_nullptr2
#include <iostream>

void foo(int* p) {}

int main()
{
	int n = 0;
	foo(0);  // ok
	foo(n);	 // error

	// 아래 코드를 생각해 보세요
	// => 함수와 인자를 줄테니 전달해 달라
	forward_parameter(&foo, 0); // foo(0) 해달라는 의미
								// 하지만, 0은 int 추론 되므로 error

	// 결론 foo 처럼 인자가 포인터인 함수를 호출할때
	// => 직접 호출시 0을 보낼수 있지만
	// => 다른 함수를 거쳐서 호출(forwarding) 하는 코드는 모두 에러.

	// 해결책 :  nullptr를 사용하면 ok
	forward_parameter(&foo, nullptr );
}

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg) // int arg = 0
{
	f(arg); // foo(int형 변수) 이므로 error
}






