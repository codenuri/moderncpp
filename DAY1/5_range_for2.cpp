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
	// 위 for 의 원리
	// => 위 코드를 컴파일러가 아래 코드로 변경합니다.
	
	// #1. v 에 대해서 반복자를 꺼내고
	auto first = std::begin(v);
	auto last = std::end(v);

	// #2. legacy for 로 변경
	for (; first != last; ++first)
	{
		auto& n = *first;
		//--------------------------------
		std::cout << n << std::endl;
	}

}















