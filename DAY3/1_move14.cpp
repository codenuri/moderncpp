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

	// 아래 함수는 인자를 객체 내부에 보관(retain) 합니다.
	// 이런 경우만 move 고려해서 2개 만들면 됩니다.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }


	// 아래 코드는 인자를 함수 내부적으로 읽기만 하고
	// 멤버 데이타에 저장하지 않습니다.
	// move 고려 대상 아닙니다.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// std::array<int, 32> 는 동적할당하는 자원 없습니다.
	// std::move() 효과가 없습니다.
	// move 고려할필요 없습니다.
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








