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
	// �Ʒ� �����ڴ� move ������ �ȵǴ� ������
	/*
	People(const std::string& n, const std::string& a) 
		: name{n}, address{a}
	{
	}
	*/
	
	// move ���� �Ϸ��� �Ʒ� ó��
	template<typename T, typename U>
	People(T&& n, U&& a)
		: name{ std::forward<T>(n) }, address{ std::forward<U>(a) }
	{
	}

	// ���ڰ� N���� setter �� move �����ϵ���
	// ���� ������� 2^N ���� �Լ��� �ʿ� �մϴ�.
	// => �� ���� T&& ����

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








