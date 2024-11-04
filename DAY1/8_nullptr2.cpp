// 8_nullptr2
#include <iostream>

void foo(int* p) {}

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)	// int arg = 0 이됩니다.
{										// f(arg) 는 에러!!
	f(arg);
}
int main()
{
	int n = 0;
	foo(0);	// ok
//	foo(n);	// error. literal 0 을 포인터로 암시적 변환되지만
			// 하지만 0으로 초기화된 변수는 포인터로 변환될수없다

	forward_parameter(foo, 0); // foo(0) 으로 호출해 달라는 의도		
								// 하지만 결국 foo(arg)가 되므로error

	forward_parameter(foo, nullptr); // ok

	// 결론, 함수 인자가 포인터 일때
	//       직접 호출이 아닌 간접호출을 사용하면 0을 전달할수 없습니다.
	//       nullptr 은 가능합니다.
}










