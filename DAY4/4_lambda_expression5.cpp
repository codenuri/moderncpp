// 145 page
#include <iostream>
int main()
{
	// 람다표현식의 정확한 모양

	// #1. 반환 타입을 표기하려면 후위 반환 타입 문법으로
	auto f1 = [](int a, int b) -> int { return a + b; };

	// #2. 반환 타입 생략시 return 문장을 보고 추론
	auto f2 = [](int a, int b) { return a + b; };

	// #3. 단, return 문장이 2개 이상이고, 서로 다른 타입 반환시는 추론안됨
	// => 아래 코드 error
	auto f3 = [](int a, double b) { if (b == 0) return a;  return a + b; };

	// 이때는 반환 타입 표기하면 됩니다.
	auto f4 = [](int a, double b)->double { if (b == 0) return a;  return a + b; };
}

