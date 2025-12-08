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

//	std::string s2 = R"(\\\\.\\pipe\\server)";
//	std::string s2 = R"(\\.\pipe\server)";


	// #1. " 출력하려면
	// => 그냥 표기하면 된다. 시작과 끝은 " 가 아닌 2문자로구성
	// std::string s2 = R"(\\.\pi"pe\s'erver)";

	// #2. )" 를 출력하려면
	// => 그냥 출력할수는 없다. 문자열 끝 기호와 충돌
	//std::string s2 = R"(\\.\pi)"pe\server)"; // error

	// 해결책 : 시작끝 변경
	// => "(  사이에 문자 추가. 아래 코드는 
	// 시작 : "*#*(
	// 끝   : )*#*"
	std::string s2 = R"*#*(\\.\pi)"pe\server)*#*"; 

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}