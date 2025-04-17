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

	chronometry(ex1);
	chronometry(ex2);
}