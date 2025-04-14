// 11_rawstring - 36 page
#include <iostream>
#include <string>

int main()
{
	// '\' Ư�� ���� ǥ�⿡  ���
	// '\' ��ü�� ����Ϸ��� 2�� ǥ���ؾ� �մϴ�.
	std::string s1 = "\\\\.\\pipe\\server";

	std::cout << s1 << std::endl;


	// Raw String : '\' �� Ư�����ڰ� �ƴ� �Ϲ� ���� ó�� ����ش޶�
	std::string s2 = R"(\\.\pipe\server)";

	std::cout << s2 << std::endl;


	// ���ڿ� �߰��� " �� ǥ���Ϸ���
	// => �׳� ǥ���ϸ� �ȴ�.
	// ���ڿ� ���� : "(
	// ���ڿ� ���� : )"
	std::string s3 = R"(\\.\pi"pe\server)";

	// ���ڿ� �߰��� )" �� ǥ���Ϸ���
	// => ���۰� �� ��ū�� ����
	std::string s4 = R"(\\.\pi)"pe\server)"; // error

	std::string s4 = R"***(\\.\pi)"pe\server)***"; 
}