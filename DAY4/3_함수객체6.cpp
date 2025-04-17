#include <iostream>
#include <algorithm>

// 1. C/C++ 에서 함수는 자신만의 타입이 없다
//    signature(반환타입과 인자)가 동일한 함수는 모두 같은 타입이다.

// 2. 함수 객체는 자신만의 타입이 있다
//    signature(반환타입과 인자)가 동일해도 모든 함수객체는 다른 타입이다


struct Less
{
	inline bool operator()(int a, int b) const { return a < b; }
};

struct Greater
{
	inline bool operator()(int a, int b) const { return a > b; }
};

//------------------------------------------------
void sort(int* x, int sz, bool(*cmp)(int, int))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]))

				std::swap(x[i], x[j]);
		}
	}
}
int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Less 	f1; f1(1, 2); 
	Greater f2; f2(1, 2); 
}