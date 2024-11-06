#include <iostream>
#include <string>

// 자동 생성 규칙.
// 규칙 #3. 사용자가 move 계열만 제공한 경우
// => 컴파일러는 복사계열은 만들지 않습니다.
// => 복사가 필요한 코드가 있다면 "컴파일 에러"

// => 복사계열의 디폴트 버전이 필요 하면 "=default"로 요청하면 됩니다.

struct Object
{
	std::string name;

	Object() = default;
	//-------------------------------	
	Object(Object&& other) noexcept : name(std::move(other.name))
	{
		std::cout << "move\n";
	}

	Object(const Object& other) = default;
	Object& operator=(Object&& other) = default;
	Object& operator=(const Object& other) = default;
};

int main()
{
	Object o1; o1.name = "object#1";
	Object o2; o2.name = "object#2";

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 

}

// 규칙 4.
// => 생성자의 사용자 제공 여부는 나머지 함수에 영향 없습니다.

// => 소멸자를 만들면 "move 계열 자동 지원(컴파일러가 자동생성) 안됩니다."
//                   "copy 는 자동 지원 됩니다."

// 왜?? 이렇게 복잡합니까?
// 소멸자가 있다는 것은 "자원 관리 한다는 것!!"
// => 따라서, 복사와 move 도 사용자가 만들어야 한다...
// => 그런데, C++98 시절, 복사는 자동생성된다는 규칙을 만들었다.
//    나중에 잘못되었다고 생각하게됨.. 