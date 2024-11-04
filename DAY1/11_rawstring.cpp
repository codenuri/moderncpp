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
	std::string s2 = R"(\\.\pipe\server)";


	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}
