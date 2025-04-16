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
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}

	// 인자가 2개인 setter 의 move 를 지원하려면
	// => 4개의 함수 필요

	// 인자가 N개인 setter 를 move 지원하려면
	// => 2^N 개의 함수가 필요 합니다

	// 좋은 방법이 없을까요 ?
	// => 완벽한 전달을 사용하면 됩니다.
	// => 다음 주제를 배운후 다시 해결

	// 인자가 N 개인 setter를 많이 사용하나요 ??
	// => 생성자가 setter 입니다.
	People(const std::string& n, const std::string& a) : name(n), age(a)
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
}








