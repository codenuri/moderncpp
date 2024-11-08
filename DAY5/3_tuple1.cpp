// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);

	auto a1 = p.first; // 1
	auto a2 = p.second; // 2.3

	std::pair<int, std::pair<int, double>> p2(1, std::pair<int, double>(3, 3.4));

	auto p3 = p2.second.second ; // 3.4

	// C++11 에서 tuple 도입
	std::tuple<int, double, char> t1(1, 3.4, 'A'); // C++11
	std::tuple t2(1, 3.4, 'A');	// C++17 부터 타입 생략 가능

	std::get<0>(t1) = 10;

	auto a4 = std::get<1>(t1); // 3.4
}

// vector, list, 배열 : 동일 타입을 여러개 보관
// tuple             : 다른 타입을 여러개 보관