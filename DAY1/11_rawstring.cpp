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


	// 문자열 중간에 " 를 표기하려면
	// => 그냥 표기하면 된다.
	// 문자열 시작 : "(
	// 문자열 종료 : )"
	std::string s3 = R"(\\.\pi"pe\server)";

	// 문자열 중간에 )" 를 표기하려면
	// => 시작과 끝 토큰을 변경
	std::string s4 = R"(\\.\pi)"pe\server)"; // error

	std::string s4 = R"***(\\.\pi)"pe\server)***"; 
}