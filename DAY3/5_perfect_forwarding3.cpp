#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}



// main					chronometry							hoo(int&&)
// hoo(10) ===================================================> 10 
// chronometry(10) ========> int&& arg = 10
//							hoo(arg) =========================> error
//							hoo(static_cast<int&&>(arg)) =====> ok

template<typename F>
void chronometry(F f, int&& arg)
{
//	f(arg);	// error.
	f(static_cast<int&&>(arg)); //ok

	// main 에서 rvalue(10) 을 전달했는데.
	// 받으면서 arg 라는 이름이 생겨서 lvalue 가 된것을
	// forwarding 할때 다시 rvalue 로 변경해서 전달
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10); // error.. 왜 안될까요 ?
}
