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
	// 핵심 : 인자가 2개인 setter

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
	// 인자가 2개인 setter 를 move 지원 하려면 : 4개 setter 필요
	// 인자가 3개인 setter 를 move 지원 하려면 : 8개 setter 필요
	// 인자가 N개인 setter 를 move 지원 하려면 : 2^N개 setter 필요
	// => 완벽한 전달 기술을 배우면 "한개"의 함수로 모두 해결 가능. 

	// 생성자가 대표적인 setter 인데, 인자2개인 경우 많습니다.
	// => 아래 코드는 move 지원안되는 생성자
	People(const std::string& n, const std::string& a)
		: name{ n }, address{ a }
	{
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


	std::pair<std::string, std::string> p(name, std::move(addr));
}








