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
			  
	// 위처럼 | 로 하지 말고 아래 처럼했다면 어떨까요 ?
	// C#(LINQ), Rust(Iterator 기술) 언어 가 아래처럼 사용합니다.
	// => method chaining 이라는 기술입니다.
	// => C++문법으로도 충분히 할수 있는데, 표준이 선택한 방식은 위 방식
//	auto rv = v.take(3).reverse();


	v[0] = 10;

//	for (auto e : tv)
	for (auto e : rv)
	{
		std::cout << e << ", ";
	}
}















