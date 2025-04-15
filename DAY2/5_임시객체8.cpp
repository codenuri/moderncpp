#include <string>
#include <iostream>

// 임시객체의 어려움을 보여주는 예제

// Max 를 만들어 봅시다.
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