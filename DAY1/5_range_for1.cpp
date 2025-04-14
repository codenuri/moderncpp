// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 문
	for (int i = 0; i < v.size(); i++)
	{
	}

	// C++11 의 새로운 for 문
	// "ranged-for" 라는 이름을 가진 문법
	// 파이썬 : for e in v
	// C#     : foreach int e in v

	for (auto e : v)	// v 에서 한개씩 꺼내서 e에 담기
	{

	}
}















