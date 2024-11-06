#include <iostream>
#include <vector>
#include <algorithm>

// C 언어의 qsort() 가 아래 처럼 비교 함수를 인자로 받게 됩니다.
// 장점 : sort 의 비교정책 변경가능
// 단점 : 느리다. 이중 루프 안에서 함수 호출
//		 cmp1, cmp2 가 인라인 이라도 함수 포인터에 담아서 호출하므로
//       인라인 치환될수 없다.

void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
		//	if (x[i] > x[j])

			if ( cmp(x[i], x[j]) == true )
				std::swap(x[i], x[j]);
		}
	}
}
//------------------------
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
}

