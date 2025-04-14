// 11_rawstring - 36 page
#include <iostream>
#include <string>

int main()
{
	// '\' 특수 문자 표기에  사용
	// '\' 자체를 출력하려면 2번 표기해야 합니다.
	std::string s1 = "\\\\.\\pipe\\server";

	std::cout << s1 << std::endl;

	// Raw String : '\' 를 특수문자가 아닌 일반 문자 처럼 사용해달라
	std::string s2 = R"(\\.\pipe\server)";

	std::cout << s2 << std::endl;
}