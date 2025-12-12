// 8_tuple1 - 245 page
#include <tuple>
#include <vector>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);
	std::pair<int, std::pair<double, char>> p2(1, { 2.3, 'A' });

	double d = p2.second.first; // 2.3

	// tuple : 서로 다른 타입 N 개를 보관 - C++11
	std::tuple<int, double, char> t3(1, 3.4, 'A');

	// 요소 접근 : get<>
	double d2 = std::get<1>(t); // 3.4 

	std::get<1>(t) = 2.1;

	// C++17 : 클래스 템플릿도 타입 추론 가능

	std::vector<int> v1 = { 1,2,3,4 };
	std::vector v2 = { 1,2,3,4 };

	
	// C++17 이전
	// => 아래 처럼 하는 것을 널리 사용
	auto t5 = std::make_tuple(1, 3.4, 'A', 10);

	// C++17 이후, 템플릿 인자 생략이 가능하므로 아래 처럼 많이 사용
	std::tuple t4(1, 3.4, 'A', 10);
}
