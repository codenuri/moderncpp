// 5_range_for4.cpp
#include <iostream>
#include <vector>
#include <ranges> // C++20 부터 지원되는 헤더. 프로젝트 메뉴 -> day1 속성메뉴에서 C++버전 20으로
				  // take_view, reverse_view, enumerate 등이 모두 이 안에 있습ㄴ다.
				  // 30여개 view 제공
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	std::ranges::take_view tv(v, 3); 

	v[0] = 100;

	//for (auto& n : v)
	for (auto& n : tv)
	{
		std::cout << n << std::endl;
	}


}















