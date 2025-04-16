#include <iostream>

void hoo(int&& arg) {}


template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main					chronometry					hoo(int&&)
// hoo(10) ============================================> ok
// chronometry(10) =====> int&& arg = 10
//						  hoo(arg) ====================> error. arg�� lvalue
//						  hoo(static_cast<int&&>(arg) => ok. 

template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10 ���� 
	// 10 �� rvalue ���� arg �� lvalue �Դϴ�.
	f(arg);	// error. hoo(int&) �� �����ϴ�. hoo(int&&) �� �ֽ��ϴ�.

	// main ����  rvalue(10)�� ���´µ�, �����鼭 lvlaue �� �Ǿ����ϴ�.
	// forwarding �Ҷ��� �ٽ� rvalue �����ؾ� �մϴ�.
	f( static_cast<int&&>(arg) ); // ok
}

int main()
{
	hoo(10); 

	chronometry(hoo, 10);	
}
