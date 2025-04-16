#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// C++11 이후 최선의 코드
	// => 복사와 이동을 각각 책임지는 2개의 setter 제공
	void set_name(const std::string& n) { name = n; } 
	void set_name(std::string&& n)      { name = std::move(n); }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1 자원 복사하라는 의도, s1은 계속 사용할것이다
	p.set_name(std::move(s2));	// s2 자원 이동하라는 의도

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

	//---------------------------
	std::vector<std::string> v;

	v.push_back(s1); // s1 자원 복사해 가라는 것
	v.push_back(std::move(s1)); // s1 자원 이동하라는 것

	// push_back 에 마우스 올리고, 오른쪽 버튼 누른후
	// => 정의로 이동 메뉴 선택
	// => push_back 구현이 몇개 있는지 확인하고
	// => 각각 인자를 보세요
}








