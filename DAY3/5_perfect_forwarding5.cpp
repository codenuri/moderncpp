#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg));  // 필요없는 캐스팅인데..
								// 있어도 됩니다.
								// 컴파일 시에 제거 됩니다.
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

// 아래 템플릿(T&&) 이 위 2개의 함수를 자동생성합니다.
// => int 뿐 아니라 모든 타입의 인자에도 사용가능합니다.
template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	// 아래 주석 주의 하세요
//	static_cast<int&&>(arg); //	rvalue 캐스팅 입니다.
//	static_cast<T&&>  (arg); //	T=int 또는 int&& 라면 rvalue 캐스팅
							 // T=int& 라면 lvalue 캐스팅

	f(static_cast<T&&>(arg)); 

	// static_cast<T&&>(arg)
	// 
	// chronometry 의 인자로
	// rvalue 를 보내면 (arg로 받으면서 lvalue가 된것을 다시) rvalue 캐스팅
	// lvalue 를 보내면 (필요없지만, 자동생성된)	           lvalue 로 캐스팅

	// 많은 설명에서 위의 () 를 제외하고 표현해서 많은 분들이 어려워 합니다.
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	// 10 은 rvalue, T = int   T&& = int&&
							// chronometry(F, int&& arg)
							// { 
							//    f(static_cast<int&&>(arg));
							// }

	chronometry(goo, n);	// n 은 lvalue, T = int&   T&& = int& && => int&
							// chronometry(F, int& arg)
							// { 
							//    f(static_cast<int&>(arg));
							// }

}
