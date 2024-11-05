#include <iostream>
#include <string>
#include <vector>

// move 개념 

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1;	// 복사 생성자
							// s1의 문자열을 깊은복사
	std::string s4 = std::move(s2);
						// s2가 가진 자원을 s4가 뺏아간다.
						// s2는 이제 자원(문자열) 없음. 

	std::cout << s1 << std::endl; // "hello"
	std::cout << s2 << std::endl; // ""


}

