#include <vector>
#include <functional> // std::less, std::greater

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 아래 코드의 단점 찾으세요
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
}