// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// sort 하고 싶다면

	// #1. 비교 정책을 전달하지 않으면 - 오름 차순 정렬
	std::sort(v.begin(), v.end());

	// #2. 일반 함수를 비교정책으로 전달 => 비교 정책의 인라인 치환이 어렵다
	std::sort(v.begin(), v.end(), &cmp);

	// #3. 함수객체를 비교 정책으로 전달
	std::less<int> f; // C++98 표준에 less 함수객체 있습니다.
					  // <functional>
	std::sort(v.begin(), v.end(), f);

	std::sort(v.begin(), v.end(), std::less<int>{}); // 임시객체로 전달

	// #4. 비교 정책으로 람다 표현식 사용 - C++
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

}





