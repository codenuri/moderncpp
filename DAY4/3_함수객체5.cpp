#include <iostream>
#include <algorithm>

// 아래 코드는 "sort 알고리즘 적용시"
// => 어떻게 비교할것인가를 3번째 인자로 받아서 
//    비교정책을 교체할수 있게 했습니다.
// => C 언어 표준 함수인 "qsort" 의 원리
// 
// 장점 : 유연성
// 단점 : 성능저하. 2중루프 안에서 비교 함수 호출

// cmp1, cmp2 가 인라인 함수라고
// => 함수 이름으로 호출하면 치환될수 있지만
// => 함수 포인터에 담아서 호출하면 치환될수 없다.


// 비교 정책을 변경하는데, 성능저하 없이(인라인치환) 할수 없을까 ?
// => C++ 의 함수 객체.. (다음 소스)


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


inline bool cmp1(int a, int b) { return a > b; }


inline bool cmp2(int a, int b) { return a < b; }






int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	sort(x, 10, cmp1); // 오름 차순 정렬 해달라는 의미
	sort(x, 10, cmp2); // 내림 차순 정렬 해달라는 의미

	for (auto e : x)
		std::cout << e << ", ";
}