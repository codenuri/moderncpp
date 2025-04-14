#include <iostream>
#include <vector>

// �Ʒ� �ڵ带 �߻����� ������
template<typename T>
class take_view
{
	T& rg;
	int cnt;
public:
	take_view(T& r, int c) : rg(r), cnt(c) {}

	// �Ʒ� 2�� �Լ��� �ٽ� �Դϴ�. �߻����� ������
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















