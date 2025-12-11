#include <iostream>

// #1. 일반 함수는 자신만의 타입이 없다.
//     signature 가 동일한 모든 함수는 같은 타입이다.

// #2. 함수객체는 자신만의 타입이 없다.
//     signature 가 동일해도 모든 함수 객체는 다른 타입이다.



struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

//---------------------------------------
// 아래 기술을, 비교정책을 교체 하는데, 비교정책의 인라인 치환도 지원하는 기술
// => template 과 함수 객체의 조합
// => 결국, "컴파일 시간 정책 교체" 기술
// 단점 : ?

template<typename T>
void Sort(int* x, int sz, T cmp)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]) == false) // cmp.operator()()
				std::swap(x[i], x[j]);
		}
	}
}
int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(5, 3); Sort(x, x + 10, f1); // ok
	Greater f2; f2(5, 3); Sort(x, x + 10, f2); // ?
}