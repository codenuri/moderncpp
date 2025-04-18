// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);

	std::pair<int, std::pair<double, char>> p2(1, { 3.4, 'A' });


	// C++11 tuple : 서로 다른 타입 몇개라도 보관 가능합니다.
	//				 보통 20개 정도 까지 보장

	std::tuple<int, double, char> t3(1, 3.4, 'A');

	// 요소 접근은 std::get<> 사용
	int n = std::get<0>(t3);

	std::get<0>(t3) = 10;

}