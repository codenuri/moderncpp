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
	// => 복사본 생성됨. 나쁜 코드
	//void set_name(std::string n) { name = n; }

	// 방법 2. call by const reference
	// C++98 에서는 "best"
	// C++11 이후는 "best"는 아님. "good" 정도!
	// => 이유 : move 지원안됨. p.set_name(std::move(s2)) 가 효과 없음.
//	void set_name(const std::string& n) { name = n; } // 항상 복사
//	void set_name(const std::string& n) { name = std::move(n); } // 항상복사(const 이므로)

	
	// 최선의 코드
	// => 2개의 setter
	void set_name(const std::string& n) { name = n; } 
	void set_name(std::string&& n)	    { name = std::move(n); }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1 문자열을 복사 해가라. s1 계속 할것이다!
	p.set_name(std::move(s2));	// s2 문자열 이동해서 사용. s2 더이상 사용 안함

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

}








