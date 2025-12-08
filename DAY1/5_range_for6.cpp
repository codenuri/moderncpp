// 5_range_for4.cpp
#include <iostream>
#include <vector>
#include <ranges>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// cppreference.com 에 접속해서 1번째 화면에서
	// => Range library 선택
	// => range adapter 찾아 보세요 (take_view 등이 여기 있습니다.)

	std::ranges::enumerate_view ev(v);

	for (auto tp : ev)
	{
		// tp 는 tuple 입니다.
		int idx = std::get<0>(tp); 
		int value = std::get<1>(tp);

		std::cout << idx << " : " << value << std::endl;		
	}


}















