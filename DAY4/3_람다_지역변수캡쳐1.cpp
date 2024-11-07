// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다표현식에서 전역변수 사용
	auto f1 = [](int a) { return a + g; }; // ok

	// #2. 람다표현식에서 지역변수 사용
	// => 캡쳐해야만 사용가능
//	auto f2 = [](int a) { return a + v1 + v2; }; // error
	auto f2 = [v1, v2](int a) { return a + v1 + v2; }; // ok

	// #3. 지역변수 수정(쓰기)
	// => "mutable lambda"로 해야 쓰기 가능
//	auto f3 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; // error
	auto f3 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; // ok
}





