#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<std::string> v = { "A", "CCC", "BB" };

	// C++20 알고리즘 특징 #1. 컨테이너 전달가능
	std::sort(v.begin(), v.end());	// 반드시 반복자로 보내야 합니다.
	std::ranges::sort(v);
}