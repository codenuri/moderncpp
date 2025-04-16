#include <iostream>
#include <string>
#include <vector>

// move 개념
// C++11 에서 처음으로 도입된 개념
// 이후 나오는 많은 언어에 영향을 주게 됩니다.
// => D, Rust, Zig, Carbon 등의 최신 언어에서 도입되었습니다



int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1; // 문자열 자체를 복사
						 // 깊은 복사
						 // s1, s3 각각 문자열 소유, s3는 계속사용가능

	std::string s4 = std::move(s2);
						// s2 의 자원(문자열) 을 s4가 빼앗아 가게 됩니다
						// 소유권(ownership) 의 이동이라고 표현
						// s2 는 더이상 문자열 자원이 없습니다.
	 
	std::cout << s1 << std::endl;	// "hello"
	std::cout << s2 << std::endl;	// ""


}

