#include <iostream>

void hoo(int&& arg) {}


template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main					chronometry					hoo(int&&)
// hoo(10) ============================================> ok
// chronometry(10) =====> int&& arg = 10
//						  hoo(arg) ====================> error. arg는 lvalue
//						  hoo(static_cast<int&&>(arg) => ok. 

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10 에서 
	// 10 은 rvalue 지만 arg 는 lvalue 입니다.
	f(arg);	// error. hoo(int&) 는 없습니다. hoo(int&&) 만 있습니다.

	// main 에서  rvalue(10)를 보냈는데, 받으면서 lvlaue 가 되었습니다.
	// forwarding 할때는 다시 rvalue 변경해야 합니다.
	f( static_cast<int&&>(arg) ); // ok
}

int main()
{
	hoo(10); 

	chronometry(hoo, 10);	
}
