#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

/*
template<typename F>
void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg)); // int& 인 arg 를 int& 로 캐스팅
							   // => 필요 없는 캐스팅 이지만
							   // => 있어도 상관없다. 컴파일시에 제거된다.
								// => 성능에도 영향없다.
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

// T&& 를 사용하면 위 2개 버전을 자동생성 할수 있습니다.


template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// 아래 캐스팅은 rvalue 캐스팅 이다 ? 아니다
	// static_cast<int&&> : 이게 rvalue casting, 아래 코드는 int 가 아닌 T

//	f(static_cast<T&&>(arg));

	// static_cast<T&&>(arg) 의미
	// chronometry 인자로
	// rvalue(10) 를 전달하면 (받으면서 lvalue 로 변하는데) 이것을 다시 rvalue 캐스팅 한것
	// lvalue(n) 를 전달하면 (필요 없는 캐스팅이지만 자동생성된 코드가) lvalue 캐스팅 한것

	f(std::forward<T>(arg)); // 위 캐스팅을 수행하는 표준함수
							 // T&& 가아닌 T 로 전달, 내부적으로 && 붙여서 캐스팅.
}


int main()
{
	int n = 10;

	chronometry(foo, 10); // T = int    T&& = int&&
						  // static_cast<int&&>(arg)

	chronometry(goo, n);  // T = int&   T&& = int& && => int&
						  // static_cast<int&>(arg)

	std::cout << n << std::endl;
}
