#include <iostream>
#include <string>


// 규칙 #1. 사용자가 복사 계열만 제공할때
// => 컴파일러는 이동 생성자의 디폴트 구현 제공 안함
// => std::move() 사용시 사용자가 만든 복사 생성자 사용.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}

	Object(const Object& other) : name{ other.name }
	{
		std::cout << "사용자가 만든 복사생성자\n";
	}
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				// 사용자가 만든 복사생성자 사용
	Object o4 = std::move(o2);  // 사용자가 만든 복사생성자 사용

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}
