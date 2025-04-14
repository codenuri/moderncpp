#include <iostream>
#include <vector>
#include <ranges> // 이 안에 이미 take_view 있습니다.
				  // 30여개의 view 가 있습니다.

int main()
{
	std::vector v = { 1,2,3,4,5, 6, 7, 8, 9,10 };

//	std::ranges::take_view tv(v, 3);
//	std::ranges::reverse_view rv(v);
//	std::ranges::reverse_view rv(tv); // view의 중첩

	// 아래 코드는 위코드와 완벽히 동일합니다.
	// => "| 연산자" 를 연산 재정의를 사용한 코딩 테크닉일 뿐입니다.

	auto rv = v | std::views::take(3) | std::views::reverse;

	v[0] = 10;
//	for (auto e : tv)
	for (auto e : rv)
	{
		std::cout << e << ", ";
	}
}















