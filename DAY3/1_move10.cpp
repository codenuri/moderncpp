#include <iostream>
#include <string>

// 자동 생성 규칙.
// 규칙 #1. 사용자가 복사 계열(복사생성자, 복사 대입연산자) 과
//			move 계열을 모두 만들지 않으면 
// => 컴파일러가 모두 제공. 
// => 아래 코드는 "복사와 move" 를 완벽히 지원하는 코드

struct Object
{
	std::string name;

	Object() = default;
	//-------------------------------	
};

int main()
{
	Object o1; o1.name = "object#1";
	Object o2; o2.name = "object#2";

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "object#1"
	std::cout << o2.name << std::endl; // ""
}
