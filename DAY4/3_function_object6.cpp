#include <iostream>
#include <vector>
#include <algorithm>


void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if (x[i] > x[j])

			if ( cmp(x[i], x[j]) == false )
				std::swap(x[i], x[j]);
		}
	}
}
//------------------------
// sort()에 전달할 비교정책 함수
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }


int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Sort(x, 10, &cmp1);
	Sort(x, 10, &cmp2);	
}

