#include <vector>
#include <functional> // std::less, std::greater

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �Ʒ� �ڵ��� ���� ã������
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
}