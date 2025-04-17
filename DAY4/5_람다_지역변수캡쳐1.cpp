// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다표현식에서 전역변수 - ok
	auto f1 = [](int a) { return a + g; };


	// #2. 람다표현식에서 지역변수 - 기본적으로는 접근 안됨
//	auto f2 = [](int a) { return a + v1 + v2; }; // error


	// #3. 접근하려면 지역변수를 캡쳐 해야 합니다.
	auto f2 = [v1, v2](int a) { return a + v1 + v2; }; // ok

	// #4. 지역변수를 변경 - error
//	auto f3 = [v1, v2](int a) { v1 = 100;  return a + v1 + v2; };

	// #4. 지역변수를 변경하려면 - mutable 람다로
	auto f3 = [v1, v2](int a) mutable { v1 = 100;  return a + v1 + v2; };//ok
}





