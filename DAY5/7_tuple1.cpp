// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : ���� �ٸ� Ÿ�� 2���� ���� - C++98
	std::pair<int, double> p(1, 2.3);

	std::pair<int, std::pair<double, char>> p2(1, { 3.4, 'A' });


	// C++11 tuple : ���� �ٸ� Ÿ�� ��� ���� �����մϴ�.
	//				 ���� 20�� ���� ���� ����

	std::tuple<int, double, char> t3(1, 3.4, 'A');

	// ��� ������ std::get<> ���
	int n = std::get<0>(t3);

	std::get<0>(t3) = 10;

}