#include <iostream>
#include <string>

// 자동 생성 규칙.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o1);

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl;
}
