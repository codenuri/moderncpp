#include <iostream>

// 주의 할점
// => emplace_back(), make_shared() 등 완벽한 전달 기술을 사용하는
//    라이브러리 사용시
// => 포인터 의미의 "0" 은 사용할수 없습니다.
// => nullptr 사용하세요

void foo(int* p) {}

template<typename F, typename T>
void chronometry(F f, T&& arg) // int&& arg = 0
{
	f(std::forward<T>(arg));
}

int main()
{
	foo(0); // ok. 직접 호출시는 0 전달 가능

//	chronometry(foo, 0); // foo(0) 해달라는 것
						 // 하지만 에러 error

	chronometry(foo, nullptr);

}









