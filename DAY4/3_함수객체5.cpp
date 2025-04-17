#include <iostream>
#include <algorithm>

// 아래 코드는 "sort 알고리즘 적용시"
// => 어떻게 비교할것인가를 3번째 인자로 받아서 
//    비교정책을 교체할수 있게 했습니다.
// 장점 : 유연성

void sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if ( x[i] > x[j] )

			if ( cmp(x[i], x[j]) )

				std::swap(x[i], x[j]);
		}
	}
}
//--------------------------------------------
bool cmp1(int a, int b) { return a > b; }
bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	sort(x, 10, cmp1); // 오름 차순 정렬 해달라는 의미
	sort(x, 10, cmp2); // 내림 차순 정렬 해달라는 의미

	for (auto e : x)
		std::cout << e << ", ";
}