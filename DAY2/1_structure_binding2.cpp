// 19_structure_binding - 52 page
#include <map>
#include <string>

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

}

