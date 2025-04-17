#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 2. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };


	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	// find_if : 3번째 인자로 "단항(인자가 한개인)함수" 를 전달
	auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 0;
	std::cin >> k;

	// 주어진 구간에서 "사용자가 입력한 k의 배수"를 찾고 싶다. 
	auto p2 = std::find_if(v.begin(), v.end(), ?);
}



