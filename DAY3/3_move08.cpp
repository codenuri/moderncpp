#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 #1. 사용자가 복사 계열과 이동 계열(이동생성자, 이동 대입연산자) 를
//          모두 만들지 않으면
// => 컴파일러가 모두 제공해 준다
// => 컴파일러 제공 복사 생성자 : 모든 멤버 데이타를 "복사" 
// => 컴파일러 제공 이동 생성자 : 모든 멤버 데이타를 "이동"

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // 일반 생성자


};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}
