#include <iostream>
#include <vector>
#include <algorithm>

// 아래 sort 는
// 장점 : 비교정책을 사용자가 변경가능하므로 유연성이 있습니다.
// 단점 : 성능. 비교시 마다 함수 호출이 발생한다. (2중 루프 안에서의 호출)
//		=> 비교 함수가 inline 이라도, 치환 될수 없습니다.(5.cpp 예제 참고)

// 비교 정책을 교체 할수 있는데, 성능저하도 없게 할수 없을까 ?
// => 함수 객체는 가능!!
// => STL 설계 철학!

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
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }


int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Sort(x, 10, &cmp1);
	Sort(x, 10, &cmp2);	
}

