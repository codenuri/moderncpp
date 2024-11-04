// 11_rawstring - 36 page
#include <iostream>
#include <string>

int main()
{
	// 일반 문자열 : \ 를 특수문자 처리.
	// => 정규 표현식, 파일 경로 등을 표기할때 \ 를 많이 사용하는데
	//    \\ 해야 하므로 복잡해 보입니다.
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw String : \ 를 일반 문자로 취급
	// R : Raw String 이라는 것을 의미
	// 문자열 시작 : "(
	//        종료 : )"
	std::string s2 = R"(\\.\pipe\server)";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	// " 를 표기하고 싶다. => 그냥 " 사용하면 된다.
	std::string s3 = R"(\\.\p"ipe\server)";

	// 종료 표기인  )" 를 출력하려면
	// 시작/종료 토큰 변경하세요
	// 아래 코드
	// 시작 : "***(
	// 종료 : )***"
	std::string s4 = R"***(\\.\pipe\s)"erver)***";
}
