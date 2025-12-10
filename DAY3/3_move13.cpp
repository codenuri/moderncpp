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
	// setter 만 move 를 지원하면 됩니다
	// 인자를 읽기만 하는 것은 move 지원 필요 없습니다.

	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// 아래 함수는 인자 msg 의 자원을 객체 내부에 보관하지 않습니다.
	// => 함수 내부적으로 읽기만 합니다.
	// => 이 경우는 rvalue 버전 필요 없습니다. 그냥. 아래 처럼만 하면됩니다.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// 아래 함수는 setter 이지만
	// => std::array<int, 32> 은 힙이 아닌 스택에 보관, raw array 와 동일
	// => move 효과 없음.
	// => 따라서, rvalue 버전 필요 없음. 
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








