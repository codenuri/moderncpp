#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙 #1. 사용자가 "복사 계열(생성자, 대입연산자) 함수와 이동 계열함수" 를 모두 만들지 않으면
// => 컴파일러가 모두 제공한다.

// => 컴파일러가 제공하는 복사 계열 함수에서는 모든 멤버를 복사 하고
// => 컴파일러가 제공하는 이동 계열 함수에서는 모든 멤버를 이동 한다.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // 생성자

};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;			// o3.name = o1.name 했다는 것. 복사
	Object o4 = std::move(o2);	// o4.name = std::move(o2.name) 했다는것

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}