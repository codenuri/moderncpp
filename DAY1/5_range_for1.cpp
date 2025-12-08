// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// C 언어 시절 부터 사용되던 for
	// => "legacy for" 라는 용어 사용하겠습니다.
	for (int i = 0; i < v.size(); i++)
	{
	}

	// C++11 의 새로운 for 문
	for (int e : v) // v의 모든 요소를 한개씩 꺼내서 e에 담기
	{
		std::cout << e << std::endl;
	}
}















