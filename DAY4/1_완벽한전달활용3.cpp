#include <iostream>
#include <string>
#include <vector>
#include <array>

class People
{
private:
	std::string name;
	std::string address;
public:
	// 아래 생성자는 move 지원이 안되는 생성자
	/*
	People(const std::string& n, const std::string& a) 
		: name{n}, address{a}
	{
	}
	*/
	
	// move 지원 하려면 아래 처럼
	template<typename T, typename U>
	People(T&& n, U&& a)
		: name{ std::forward<T>(n) }, address{ std::forward<U>(a) }
	{
	}

	// 인자가 N개인 setter 를 move 지원하도록
	// 직접 만들려면 2^N 개의 함수가 필요 합니다.
	// => 이 경우는 T&& 권장

	template<typename T, typename U>
	void set(T&& n, U&& a)
	{
		name = std::forward<T>(n);
		address = std::forward<U>(a);
	}
};




int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p(name, std::move(addr));

	p.set(name,			   addr);
	p.set(std::move(name), addr);
	p.set(name,			   std::move(addr));
	p.set(std::move(name), std::move(addr));

	std::pair<int, double> pa(1, 3.4);
}








