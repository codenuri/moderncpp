#include <iostream>
#include <vector>
#include <ranges> // C++20 에서 도입되는 다양한 view(시각)들..

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 아래 모든 코드는 "데이타의 복사본"을 만들지는 않습니다.
	// 단지, 시각(view) 만 제공합니다
	// 중첩이된다는 것이 핵심
//	std::ranges::take_view tv(v, 3);
//	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 1; });
//	std::ranges::reverse_view rv(fv);

	// 아래 코드는 위코드와 동일합니다.(간단한 테크닉으로 만든것)
	auto rv = v | std::views::take(3)
				| std::views::filter([](int n) { return n % 2 == 1; })
				| std::views::reverse;


	for (auto& n : rv) // <===
	{
		std::cout << n << std::endl;
	}
}















