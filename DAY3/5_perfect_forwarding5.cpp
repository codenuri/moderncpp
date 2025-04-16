#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg));  // �ʿ���� ĳ�����ε�..
								// �־ �˴ϴ�.
								// ������ �ÿ� ���� �˴ϴ�.
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

// �Ʒ� ���ø�(T&&) �� �� 2���� �Լ��� �ڵ������մϴ�.
// => int �� �ƴ϶� ��� Ÿ���� ���ڿ��� ��밡���մϴ�.
template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	// �Ʒ� �ּ� ���� �ϼ���
//	static_cast<int&&>(arg); //	rvalue ĳ���� �Դϴ�.
//	static_cast<T&&>  (arg); //	T=int �Ǵ� int&& ��� rvalue ĳ����
							 // T=int& ��� lvalue ĳ����

	f(static_cast<T&&>(arg)); 

	// static_cast<T&&>(arg)
	// 
	// chronometry �� ���ڷ�
	// rvalue �� ������ (arg�� �����鼭 lvalue�� �Ȱ��� �ٽ�) rvalue ĳ����
	// lvalue �� ������ (�ʿ������, �ڵ�������)	           lvalue �� ĳ����

	// ���� ������ ���� () �� �����ϰ� ǥ���ؼ� ���� �е��� ����� �մϴ�.
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	// 10 �� rvalue, T = int   T&& = int&&
							// chronometry(F, int&& arg)
							// { 
							//    f(static_cast<int&&>(arg));
							// }

	chronometry(goo, n);	// n �� lvalue, T = int&   T&& = int& && => int&
							// chronometry(F, int& arg)
							// { 
							//    f(static_cast<int&>(arg));
							// }

}
