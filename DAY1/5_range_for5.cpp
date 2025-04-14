#include <iostream>
#include <vector>
#include <ranges> // 이 안에 이미 take_view 있습니다.
				  // 30여개의 view 가 있습니다.

int main()
{
	std::vector v = { 1,2,3,4,5, 6, 7, 8, 9,10 };

	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(v);

//	for (auto e : tv)
	for (auto e : rv)
	{
		std::cout << e << ", ";
	}
}















