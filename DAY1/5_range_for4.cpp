#include <iostream>
#include <vector>

// 아래 코드를 잘생각해 보세요
template<typename T>
class take_view
{
	T& rg;
	int cnt;
public:
	take_view(T& r, int c) : rg(r), cnt(c) {}

	// 아래 2개 함수가 핵심 입니다. 잘생각해 보세요
	auto begin() { return rg.begin(); }
	auto end() { return std::next(rg.begin(), cnt); }
};
int main()
{
	std::vector<int> v = { 1,2,3,4,5, 6, 7, 8, 9,10 };
	
	take_view tv(v, 3);

//	for (auto e : v)	
	for (auto e : tv)	
	{
		std::cout << e << ", ";
	}
}















