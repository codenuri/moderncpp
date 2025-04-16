#include <iostream>
#include <string>


// 규칙 #2. 사용자가 복사 계열만 제공한 경우
// => 컴파일러는 이동 계열 함수를 제공하지 않는다.
// => 이동이 필요한 코드가 있으면 "복사 계열(생성자)" 사용한다.

// 이때, 이동계열이 필요하면 컴파일러에게 "=default" 로 요청하면 된다.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // 생성자

	Object(const Object& other) : name(other.name)
	{
		std::cout << "사용자가 만든 복사 생성자\n";
	}

	// "=default" 요청시, 이동생성자 뿐아니라 = 연산자도 같이 하는 것이 관례
	Object(Object&&) = default;

	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
};


int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				// 사용자가 만든 복사 생성자 호출	
	Object o4 = std::move(o2);	// 사용자가 만든 복사 생성자 호출
								// "=default"로 요청했다면, 컴파일러 제공버전사용

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl; 
}