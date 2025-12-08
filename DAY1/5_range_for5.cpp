// 5_range_for4.cpp
#include <iostream>
#include <vector>
#include <ranges> // C++20 부터 지원되는 헤더. 프로젝트 메뉴 -> day1 속성메뉴에서 C++버전 20으로
				  // take_view, reverse_view, enumerate 등이 모두 이 안에 있습ㄴ다.
				  // 30여개 view 제공
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	std::ranges::take_view tv(v, 4); 
//	std::ranges::reverse_view rv(v);
	std::ranges::reverse_view rv(tv); // 핵심 : 중첩도 허용  => 4 ,3, 2, 1
	std::ranges::filter_view fv(rv, [](int n) { return n % 2 == 0; }); //4, 2

	v[0] = 100;

	for (auto& n : rv)
	{
		std::cout << n << std::endl;
	}


}















