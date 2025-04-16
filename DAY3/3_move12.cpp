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
	// 방법 1. call by value
	// => 복사본 생성되므로 좋지 않은 코드
//	void set_name(std::string n) { name = n; }


	// 방법 2. call by const reference
	// => C++98 시절은 best!!
	// => C++11 이후는 나쁘지는 않지만 최선은 아님
	// => 이유 : move 지원 안됨
	void set_name(const std::string& n) { name = n; }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

}








