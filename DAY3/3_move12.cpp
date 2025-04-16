#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;

public:
	// ��� 1. call by value
	// => ���纻 �����ǹǷ� ���� ���� �ڵ�
//	void set_name(std::string n) { name = n; }


	// ��� 2. call by const reference
	// => C++98 ������ best!!
	// => C++11 ���Ĵ� �������� ������ �ּ��� �ƴ�
	// => ���� : move ���� �ȵ�
	void set_name(const std::string& n) { name = n; }
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








