#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ 표준의 std::sort() 는 모든 인자가 template 입니다.
	// => 사용자가 전달하는 인자의 타입에 따라 sort() 함수가 생성된다는 의미.

	// #1. 비교 정책으로 일반 함수를 사용할때
	
	// 장점 : 비교 정책을 교체해도 sort() 함수는 한개만 생성된다
	//		 "코드 메모리 증가 안함"

	// 단점 : 비교함수가 치환 될수 없다. 느리다.
	//		 => 데이타가 많다면 오버헤드가 크다.

	std::sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int) ) 인함수생성
	std::sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int) ) 인함수생성 - 같은 함수 사용

	// #2. 비교 정책으로 함수객체를 사용할때

	// 장점 : 비교 정책이 인라인 치환됨. 아주 빠르다!

	// 단점 : 비교정책을 교체한 횟수 만큼의 sort() 함수 생성
	//       => 코드 메모리 증가

	Less f1;
	Greater f2;
	std::sort(x, x + 10, f1); // sort(int*, int*, Less) 인 함수 생성
	std::sort(x, x + 10, f2); // sort(int*, int*, Greater) 인 함수 생성

}