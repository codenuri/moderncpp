#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:
	// set_name 인 인자로 받은 문자열을 내부적으로 "보관" 합니다.
	// => 따라서 move 를 고려한 setter 필요
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// 아래 함수는 전달받은 문자열을 보관하는 것이 아니라
	// 함수 안에서 사용만 합니다.
	// => move 버전 고려할필요 없습니다.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// 아래 함수는 인자를 멤버 데이타에 보관하지만
	// => std::array<int, 32> 는 move 효과 없습니다.
	// => setter 의 move 버전 고려할 필요 없습니다.
	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	std::string s = "hello";
	std::array<int, 32> arr = {0};

	People p;

	p.print_msg(s);
	p.set_data(arr);
}








