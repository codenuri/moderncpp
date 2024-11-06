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
	// call by value - 나쁜 코드, 사용하지 마세요
	// void set_name(std::string n) { name = n; }

	// # const lvalue reference
	// C++98 : best
	// C++11 : 나쁘지 않지만 best 는 아님. 
	//			=> 아래 setter 는 move 지원 안됨.
//	void set_name(const std::string& n) { name = n; }		// 항상복사
//	void set_name(const std::string& n) { name = std::move(n); } //항상복사
														// n 은 const 이므로
	// 해결책 : 2개 만들어야 합니다.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};
int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// 자원 복사해 가라는 의미
	p.set_name(std::move(s2));	// 자원 이동해 가라는 의미

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

}








