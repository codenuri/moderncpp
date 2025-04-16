#include <iostream>
#include <string>


// 규칙 #2. 사용자가 이동 계열만 제공한 경우
// => 컴파일러는 복사 계열을 만들지 않는다.
// => 복사가 필요한 코드가 있으면 "에러"
//    복사가 필요 할때 "이동"을 사용할수 없다.

// 이때, 복사계열이 필요하면 컴파일러에게 "=default" 로 요청하면 된다.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // 생성자

	Object(Object&& other) : name(std::move(other.name) )
	{
		std::cout << "사용자가 만든 이동 생성자\n";
	}
	
	// 이동생성자를 제외한 나머지를 디폴트 요청
	Object(const Object&) = default;
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;				
	Object o4 = std::move(o2);	

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl;
}