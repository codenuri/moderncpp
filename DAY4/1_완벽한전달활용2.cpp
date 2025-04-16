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
	// move 를 지원하는 setter 만들기 
	// 
	// #1. 2개의 setter
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }


	// #2. T&& 를 사용하면 lvalue &, rvalue & 버전을 자동생성가능
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
		name = n;					// 1. 
		name = std::move(n);		// 2. 
		name = std::forward<T>(n);	// 3.
	}
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








