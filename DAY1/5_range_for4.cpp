#include <iostream>
#include <vector>

// 아래 클래스를 잘생각해보세요
template<typename T>
class take_view
{
	T& c;
	int cnt;
public:
	take_view(T& c, int cnt) : c(c), cnt(cnt) {}

	auto begin() { return c.begin(); }
	auto end() { return c.begin() + cnt; } // 핵심!! 잘생각해 보세요
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	take_view tv(v, 3);

//	for (auto& n : v)
	for (auto& n : tv)
	{
		std::cout << n << std::endl;
	}
}















