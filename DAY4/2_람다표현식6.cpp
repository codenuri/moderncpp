// 145 page
#include <iostream>
int main()
{
	// 람다표현식의 정확한 모양
	// => 리턴 타입은 후위 반환 표기법( -> 타입) 으로 표기

	auto f1 = [](int a, int b) -> int { return a + b; };

	// return 문장이 2개이상이고, 서로 다른 타입일때만
	// 표기하면 됩니다. 

	auto f2 = [](int a, double b) { if (a == 0) return a; return b; };
}

