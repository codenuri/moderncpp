#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// move 지원 setter 만들기 #1. 2개의 setter
	// void set_name(const std::string& n) { name = n; }
	// void set_name(std::string&& n)      { name = std::move(n); }



	// move 지원 setter 만들기 #2. T&& 사용
	// => 위 2개 버전을 자동으로 생성할수 있다.
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
	//	name = n;				// 무조건 copy
	//	name = std::move(n);	// 무조건 move - std::move() : 무조건 rvalue 캐스팅
		name = std::forward<T>(n); // 인자로 lvalue 를 보내면 copy
									// 인자로 rvalue 를 보내면 move
	}

	// 이 경우는 인자가 한개인 setter 이므로
	// => template 보다는 2개 만드는 것 권장..
	// => 그런데, 인자가 2개 이상이면,, template !!! - 다음예제..
};












int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

}








