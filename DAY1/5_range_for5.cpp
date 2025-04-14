#include <iostream>
#include <vector>
#include <ranges> // �� �ȿ� �̹� take_view �ֽ��ϴ�.
				  // 30������ view �� �ֽ��ϴ�.

int main()
{
	std::vector v = { 1,2,3,4,5, 6, 7, 8, 9,10 };

//	std::ranges::take_view tv(v, 3);
//	std::ranges::reverse_view rv(v);
//	std::ranges::reverse_view rv(tv); // view�� ��ø

	// �Ʒ� �ڵ�� ���ڵ�� �Ϻ��� �����մϴ�.
	// => "| ������" �� ���� �����Ǹ� ����� �ڵ� ��ũ���� ���Դϴ�.

	auto rv = v | std::views::take(3) | std::views::reverse;

	v[0] = 10;
//	for (auto e : tv)
	for (auto e : rv)
	{
		std::cout << e << ", ";
	}
}















