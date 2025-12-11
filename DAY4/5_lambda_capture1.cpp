// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 1. 람다표현식에서 전역변수
	auto f1 = [](int a) { return a + g; }; // ok. 사용가능.

	// 2. 람다표현식에서 지역변수
	// => 캡쳐해야만 사용가능
//	auto f2 = [](int a) { return a + v1 + v2; }; // error.

	auto f2 = [v1, v2](int a) { return a + v1 + v2; }; // ok

	// 3. 캡쳐된 변수 수정
	// => mutable 람다로 만들면 변경 가능. 
//	auto f3 = [v1, v2](int a) { v1 = 200; return a + v1 + v2; }; // error
	auto f3 = [v1, v2](int a) mutable { v1 = 200; return a + v1 + v2; }; // ok

	// 이외에도 복잡한 현상이 많은데..
	// => 외우지 말고
	// => 원리를 이해 하세요. 
}





