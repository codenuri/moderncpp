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
}