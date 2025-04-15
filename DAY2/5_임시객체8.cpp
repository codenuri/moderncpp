#include <string>
#include <iostream>

// �ӽð�ü�� ������� �����ִ� ����

// Max �� ����� ���ô�.
// 1. ���ڴ� "���纻"�� �����ϱ� ���� const std::string& ��!
// 2. ���Ͽ� �ӽð�ü�� �����ϱ� ���� const std::string& 
const std::string& Max(const std::string& a, const std::string& b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";

//	std::string s3 = Max(s1, s2); 
					// �������� ���ƿ°��� ���纻�� �ƴ� s2 �ε�
					// �װ��� s3�� ����
					// std::string s3 = s2 �� �ǹ�

	const std::string& ret = Max(s1, s2);
					// ret �� �ᱹ s2 �� ����!

	// ����, �Ʒ� �ڵ� �����ұ�� ?
	const std::string& ret2 = Max(std::string{ "A" }, std::string{ "B" });

	// ret2 ����ص� �ɱ��?
}

// cppreference.com ���� std::max �˻�