#include <iostream>
#include <string>


// 규칙 #3. 사용자가 이동 계열만 제공한다면
// => 컴파일러는 복사 계열 제공 안함

// => 이 경우도 복사 생성자 기본 구현이 필요 하면 "=default"로 요청하면 됩니다.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}

	Object(Object&& other) : name{ std::move(other.name) }
	{
		std::cout << "사용자가 만든 이동 생성자\n";
	}

	/*
	Object(const Object&) = default;
	Object& operator=(const Object&) = default; // 복사 버전
	Object& operator=(Object&&) = default;      // 이동 버전
	*/
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;			    // error. 복사 생성자 없음.
	Object o4 = std::move(o2);  // 사용자가 만든 이동생성자 사용

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl;
}
