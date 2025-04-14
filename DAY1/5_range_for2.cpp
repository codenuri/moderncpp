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

	// 위 range-for 의 원리
	// => 컴파일러가 아래 처럼 변경합니다.
	auto first = std::begin(v);
	auto last = std::end(v);

	for (; first != last; ++first)
	{
		auto& n = *first;
		//----------------------------------
		std::cout << n << std::endl;
	}
}















