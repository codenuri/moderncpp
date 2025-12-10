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
	f(static_cast<T&&>(arg));
}


int main()
{
	int n = 10;

	chronometry(foo, 10); // T = ?    T&& = ?
						  // static_cast<?>(arg)

	chronometry(goo, n);  // T = ?    T&& = ?
						  // static_cast<?>(arg)

	std::cout << n << std::endl;
}
