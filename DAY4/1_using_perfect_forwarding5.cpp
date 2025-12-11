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
	People(const std::string& n, const std::string& a)
		: name{ n }, address{ a }
	{
	}

	// 인자가 2개인 setter 를 move 지원하려면
	// 직접만들면 :4개 필요
	// forwarding reference 로 하면 자동 생성

	template<typename T1, typename T2>
	void set(T1&& n, T&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}
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








