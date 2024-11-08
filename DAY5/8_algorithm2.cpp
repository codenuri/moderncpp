#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<std::string> v = { "A", "BBB", "CC" };

	std::sort(v.begin(), v.end());	// 문자열 자체를 < 연산자로 비교
									// 즉, 사전순서

	// 사전순서가 아닌 "문자열 길이 순서"로 정렬하고 싶다.

	// C++98 : 비교 정책으로 "이항 함수 전달"
	std::sort(v.begin(), v.end(), 
			[](const std::string& s1, const std::string& s2) 
				{ return s1.size() < s2.size(); } );


	std::ranges::sort(v);
	
}