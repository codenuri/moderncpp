#include <iostream>
#include <vector>
#include "chronometry.h"

// 람다 표현식의 장점 #2.
// => 일반 함수 보다 빠를때가 있다.
// => "함수 를 다른 함수에 인자로 전달할때"
// => 빠른 이유는 "인라인 치환" - 이어지는 원리에서 자세히

// 그외에도 많은 장점이 있고
// 일부 단점도 있습니다.
// => 원리를 알면 모두 이해 가능합니다.
// => 원리를 알려면 "function object" 를 알아야 합니다.

bool is_odd(int n) { return n % 2 == 1; }

constexpr int size = 100'000'000; // 1억
std::vector<int> v1(size, 0);
std::vector<int> v2(size, 0);

void init()
{
	// 1억개 요소의 벡터, 마지막요소만 1 나머지는 0
	v1[size - 1] = 1;
	v2[size - 1] = 1;
}

void ex1()
{
	// 아래 코드는 1억번의 is_odd 호출
	auto ret = std::find_if(v1.begin(), v1.end(), is_odd);
}
void ex2()
{
	// 아래 코드는 일반 함수가 아닌 람다 표현식
	auto ret = std::find_if(v2.begin(), v2.end(), [](int n) { return n % 2 == 1; });
}

int main()
{
	init();

	chronometry(ex1);
	chronometry(ex2);
	chronometry(ex1);
	chronometry(ex2);
}