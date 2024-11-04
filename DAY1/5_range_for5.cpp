#include <iostream>
#include <vector>
#include <ranges> // C++20 에서 도입되는 다양한 view(시각)들..

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	std::ranges::take_view tv(v, 3);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 1});
	std::ranges::reverse_view rv(fv);


	for (auto& n : rv) // <===
	{
		std::cout << n << std::endl;
	}
}















