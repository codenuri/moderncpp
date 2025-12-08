// 19_structure_binding - 52 page
#include <map>
#include <string>
#include <vector>
#include <ranges>

int main()
{
	std::map<std::string, std::string> m;
	
	// C++ 표준의 map 에 데이타 넣기
	// #1. 제일 편한 방법
	m["mon"] = "월요일";

	// #2. 정확한 원리는 pair 라는 구조체를 만들어서 넣는것
	// => 위 코드는 아래 코드와 동일
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";
	m.insert(p);

	// C++17 이전에 map 의 모든 요소 열거
	for (auto p : m)
	{
		// p는 pair 입니다.
		auto key = p.first;
		auto value = p.second;
	}

	// C++17 이후
	for (auto [key, value] : m)
	{
	}

	std::vector<int> v = { 1,2,3,4,5 };

	for (auto n : v) // 요소만 열거. 
	{
	}

	// 아래 코드는 C++23
	for (auto [idx, value] : std::ranges::enumerate_view(v)) // index, 요소 를 tuple로
	{
	}
}

