#include <iostream>
#include <algorithm>
#include <vector>
#include "chronometry.h"

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

std::vector<int> v1;
std::vector<int> v2;

constexpr std::size_t COUNT = 1000000;

void init()
{
	v1.reserve(COUNT);
	v2.reserve(COUNT);

	for (std::size_t i = 0; i < COUNT; ++i)
	{
		int n = rand();

		v1.push_back(n);
		v2.push_back(n);
	}
}

void ex1()
{
	// 비교 함수로 일반함수를 사용하는 버전
	std::sort(v1.begin(), v1.end(), cmp1);
	std::sort(v1.begin(), v1.end(), cmp2);
}

void ex2()
{
	// 비교 함수로 함수 객체 사용
	Less f1;
	Greater f2;
	std::sort(v2.begin(), v2.end(), f1);
	std::sort(v2.begin(), v2.end(), f2);
}

int main()
{
	init();

//	chronometry(ex1);
	chronometry(ex2);
	chronometry(ex1);
}

// 참고 : 함수 타입과 함수 포인터 타입 을 잘 구별해 두세요
// => 처음 보시는 분은 "C" 언어 에서 찾아 보세요

//int cmp(int a, int b) 에서

// 함수 타입        : int(int, int)
// 함수 포인터 타입 : int(*)(int, int)

// C/C++ : signature 가 동일한 함수는 같은 "타입" 이고
//         따라서, 같은 "함수포인터 타입" 이다.
// 
// Rust : 모든 함수는 "다른 타입" 이다.
//        signature 가 동일한 함수도 다른 타입이다.
//        하지만 signature 가 동일한 함수는 같은 함수 포인터 타입에 담을수 있다.
// 
// 
//		