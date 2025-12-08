// 5_range_for4.cpp
#include <iostream>
#include <vector>

// range-for 사용시 자주 나오는 질문
// => 2칸씩 이동 안됩니까 ? 뒤에서 부터 열거 안되나요 ?
// => index 를 같이 꺼내려면 어떻게 하나요 ?

// 아래 코드는 약간 어려운 코드인데, 잘생각해 보세요 - range-for 원리가 중요
template<typename T>
class take_view
{
	T& rng;
	int cnt;
public:
	take_view(T& r, int c) : rng(r), cnt(c) {}

	auto begin() { return rng.begin(); }		// vector 의 begin()
	auto end()   { return rng.begin() + cnt; }	// vector 의 begin() + cnt(3) 의 위치
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	take_view tv(v, 3); // 이 순간 데이타 복사본을 만드는 것은 아님

	v[0] = 100;

	//for (auto& n : v)
	for (auto& n : tv)
	{
		std::cout << n << std::endl;
	}


}















