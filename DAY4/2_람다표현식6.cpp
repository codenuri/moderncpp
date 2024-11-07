// 145 page
#include <iostream>
int main()
{
	// 람다표현식의 정확한 모양
	// => 리턴 타입은 후위 반환 표기법( -> 타입) 으로 표기

	auto f1 = [](int a, int b) -> int { return a + b; };

	// return 문장이 2개이상이고, 서로 다른 타입일때만
	// 표기하면 됩니다. 

	// => 아래 코드는 에러 입니다.
//	auto f2 = [](int a, double b) { if (a == 0) return a; return b; };

	// 아래처럼 반환타입 표기하면 에러 아닙니다.
	auto f2 = [](int a, double b) -> double { if (a == 0) return a; return b; };
}

