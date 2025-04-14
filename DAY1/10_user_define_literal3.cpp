// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

using namespace std::literals; // �̾ȿ� ��� ǥ�� ���ͷ� �ֽ��ϴ�.
							   // 35 page ������ ���� �μ���

void foo(const char* s) { std::cout << "char*\n"; }
void foo(std::string s) { std::cout << "string\n"; }

int main()
{
	foo("hello");  // const char* 
	foo("hello"s); // string, ������ 
				   // std::string operator""s("hello")�� ǥ�ؿ�����
				
	// C++ ǥ���� �ð� ���� Ÿ��
	std::chrono::seconds s1(30);
	auto s2 = 30s; // ���� ����

	auto s3 = 1h + 3min + 2s;
	std::cout << s3.count() << std::endl; // 3600+180+2

	// C++17 ���� vector ���� Ÿ�Ի��� �����մϴ�.
	// => �ʱⰪ���� �߷�
	std::vector v1 = { "AB", "CD" };
	std::vector v2 = { "AB"s, "CD"s };
}


