// 8_nullptr2
#include <iostream>

void foo(int* p)
{
}

template<typename T>
void forward_foo(T arg)	// int arg = 0 로 T가 결정됩니다.
{						// foo(arg) 는 에러
						// std::nullptr_t arg = nullptr;
	foo(arg);			// foo(arg) 는 ok.. 
}

int main()
{
	foo(0); //ok

//	forward_foo(0); // error 왜 에러인지 생각해 보세요
	
	forward_foo(nullptr); // ok.
}







