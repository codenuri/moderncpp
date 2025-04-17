// 145 page
#include <iostream>

int main()
{
	// 람다표현식의 정확한 모양
	// => 후위 반환 타입으로 리턴 타입 표기
	auto f1 = [](int a, int b) -> int { return a + b; };

	// return 문장으로 반환 타입 추론이 가능한 경우 생략 가능

	auto f2 = [](int a, int b)  { return a + b; }; // ok


	auto f3 = [](int a, int b)  { if (a == 0) return b;  return a + b; };

	// 아래 코드는 2개 이상의 return 문장이 다른 타입을 반환하므로
	// 반드시 반환 타입 표기해야 합니다.
	// 표기하지 않으면 에러. 
	auto f4 = [](double a, int b) { if (a == 0) return b;  return a + b; };

}

