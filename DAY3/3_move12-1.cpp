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
	// C++11 ���� �ּ��� �ڵ�
	// => ����� �̵��� ���� å������ 2���� setter ����
	void set_name(const std::string& n) { name = n; } 
	void set_name(std::string&& n)      { name = std::move(n); }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1 �ڿ� �����϶�� �ǵ�, s1�� ��� ����Ұ��̴�
	p.set_name(std::move(s2));	// s2 �ڿ� �̵��϶�� �ǵ�

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

	//---------------------------
	std::vector<std::string> v;

	v.push_back(s1); // s1 �ڿ� ������ ����� ��
	v.push_back(std::move(s1)); // s1 �ڿ� �̵��϶�� ��

	// push_back �� ���콺 �ø���, ������ ��ư ������
	// => ���Ƿ� �̵� �޴� ����
	// => push_back ������ � �ִ��� Ȯ���ϰ�
	// => ���� ���ڸ� ������
}








