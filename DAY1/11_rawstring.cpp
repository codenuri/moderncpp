// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// 일반 문자열 : "\" 문자를 특수 문자로 처리합니다.
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw Strng : "\" 를 특수 문자로 처리하지 말라
	// R : Raw String 의 의미
	// 문자열 시작 : "(
	// 문자열 끝   : )"

	std::string s2 = R"(\\\\.\\pipe\\server)";


	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}