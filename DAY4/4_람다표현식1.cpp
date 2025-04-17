// 5_람다표현식1 - 139
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면

	// #1. 비교정책 생략시 오름 차순 정렬
	std::sort(v.begin(), v.end()); 


	// #2. 비교 정책 전달 - 일반함수
	// => 비교 정책이 인라인 치환 안됨
//	std::sort(v.begin(), v.end(), cmp1);


	// #3. 비교 정책 전달 - 함수 객체 
	// => C++ 98 표준에 이미 다양한 함수 객체 있습니다.
	// => <functional> 헤더
	std::less<int> f1;
	std::greater<int> f2;

	std::sort(v.begin(), v.end(), f1);
	std::sort(v.begin(), v.end(), std::less<int>{}); // 임시객체형태로
	std::sort(v.begin(), v.end(), std::less{}); // C++17 이후 타입생략가능

}





