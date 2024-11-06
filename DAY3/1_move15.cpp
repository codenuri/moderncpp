#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// 인자가 2개인 setter
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}

	// 인자가 2개인 setter 를 move 지원하려면 "4개" 필요 합니다.
	// 인자가 N개인 setter 를 move 지원하려면 "2^N" 개 필요 
	// => 너무 많습니다.
	// => forwarding reference 와 perfect forwarding 으로 하면
	//    모두 자동생성 가능합니다.
};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
	p.set(std::move(name), addr);
	p.set(name,			   std::move(addr));
	p.set(std::move(name), std::move(addr));
}








