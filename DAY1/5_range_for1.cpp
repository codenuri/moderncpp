﻿// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 문
	for (int i = 0; i < v.size(); i++)
	{
	}

	// C++11 의 새로운 for 문 - range for 문이라고 합니다.
	// 파이썬 : for e in v
	for (auto e : v)
	{
	}
}















