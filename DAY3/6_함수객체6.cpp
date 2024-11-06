#include <iostream>

// #1. 함수는 자신만의 타입이 없다.
//     signature(반환타입과 인자 모양)가 동일한 함수는 모두 같은 타입이다.

// #2. 함수객체는 자신만의 타입이 있다.
//     signature(반환타입과 인자 모양)가 동일해도 
//     모든 함수객체는 다른 타입이다.


struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

//======================================================
// 비교 정책을 교체할수 있는데, 
// 비교 정책 함수의 인라인 치환도 가능한 Sort
// => STL 의 설계 원리
// => 함수객체 + 템플릿으로 만드는 기술
template<typename T>
void Sort(int* x, int sz, T cmp)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]) == true)
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(5, 3); Sort(x, 10, f1); // ok
	Greater f2; f2(5, 3); Sort(x, 10, f2); // ok
}