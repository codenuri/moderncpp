#include <string>
#include <iostream>

// �ӽð�ü�� ������� �����ִ� ����

// Max �� ����� ���ô�.
std::string Max(std::string a, std::string b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";

	std::string s3 = Max(s1, s2);
}