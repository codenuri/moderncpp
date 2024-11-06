#include <iostream>
#include <string>
#include <vector>

class People
{
private:
	std::string name;
	int age;

public:
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n) { name = std::move(n); }
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








