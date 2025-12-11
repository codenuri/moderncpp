#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }

class IsMod
{
	int value;
public:
	IsMod(int n) : value{ n } {}

	bool operator()(int n)
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	// 주어진 구간에서 "k의 배수"를 찾고 싶다. 
	// => foo 안에서 "3" 대신 "k" 로 변경해야 하는데.
	// => foo 에서는 main 의 지역변수 사용못함!!
	auto p1 = std::find_if(v.begin(), v.end(), foo);


}



