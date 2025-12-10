#include <iostream>
#include <string>
#include <vector>

// move 개념

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	// 아래 2줄이 실행될때, 메모리 구조가 핵심(문자열 메모리)
	std::string s3 = s1;	// 깊은 복사 발생
							// s3는 자신의 메모리를 할당해서 사용
							// s1, s3 는 각 문자열 보유
	std::string s4 = std::move(s2);
							// s2 의 자원을 s4로 이동(메모리주소복사)
							// 이후 부터는 s2 는 문자열 자원 없음!!!
							// s2 는 사용하지 않는게 좋음. 

	std::cout << s1 << std::endl; // "to be or not to be"
	std::cout << s2 << std::endl; // ""


}









