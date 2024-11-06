// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)  // int&& arg = 0, foo(arg) 는 에러
{
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
	foo(0); // ok

	// 핵심 : 완벽한 전달 기술로 만든 라이브러리 사용시
	//        인자로 "포인터의미의 0"은 사용할수 없습니다.
	//        nullptr 로 하세요
//	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // ok.

}









