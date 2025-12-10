#include <iostream>
#include <string>

// rule of 0  => 권장

// 자원을 직접 관리하지 말고, 자원 관리 클래스에 의존하라!

// 문자열이 필요 하면 : std::string
// 동적배열이 필요    : 스마트 포인터 또는 std::vector

// 자원을 직접 관리하지 않으면
// => 소멸자, 복사 생성자, 대입연산자, 이동생성자, 이동대입 모두 필요 없다!!
// => 하지만 컴파일러가 모두 완벽하게 제공..
// => 가장 잘만든 코드. 

class Cat
{
	std::string name;
	int   age;
	std::string address;

public:
	Cat(const std::string& n, int a, const std::string& addr = "unknown")
		: name{ n }, age {a}, address{ addr }
	{
	}
};

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;
	c2 = c1;

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




