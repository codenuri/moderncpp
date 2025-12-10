#include <iostream>
#include <string>


// 규칙 #1. 사용자가 복사 계열만 제공할때
// => 컴파일러는 이동 생성자의 디폴트 구현 제공 안함
// => std::move() 사용시 사용자가 만든 복사 생성자 사용.

// 이경우, 컴파일러에게 이동의 기본 구현을 요청하려면
// => "= default" 사용

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}

	Object(const Object& other) : name{ other.name }
	{
		std::cout << "사용자가 만든 복사생성자\n";
	}

	// 관례적으로 대입연산도 같이 요청
	Object(Object&&) = default;
	Object& operator=(const Object&) = default; // 복사 버전
	Object& operator=(Object&&) = default;      // 이동 버전

};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				// 사용자가 만든 복사생성자 사용
	Object o4 = std::move(o2);  // 사용자가 만든 복사생성자 사용
								// 단, =default 가 있다면
								// 컴파일러 제공버전 사용

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}
