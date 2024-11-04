// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	for (auto& n : v) 
	{
		std::cout << n << std::endl;
	}

	// 위코드를 컴파일러가 아래 처럼변경합니다.
	auto first = std::begin(v); // 또는 v.begin()
	auto last  = std::end(v);

	for (; first != last; ++first)
	{
		auto& n = *first;
		//-----------------------------
		std::cout << n << std::endl;
	}
}















