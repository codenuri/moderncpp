#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// move 를 지원하는 setter 만들기 
	// 
	// #1. 2개의 setter
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }


	// #2. T&& 를 사용하면 lvalue &, rvalue & 버전을 자동생성가능
	// => 그런데, 아래 처럼 하면 lvalue string, const lvalue string 등을
	//    각각생성하게 됩니다.
	// => 위 모양은 "set_name(const std::string& n)" 버전에서 모두 처리 가능
	// => 인자가 한개인 setter 는 아래 코드 보다는 #1 을 권장
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
//		name = n;					// 1. 항상 복사 생성자 호출
//		name = std::move(n);		// 2. 항상 이동 생성자 호출

		// 아래 캐스팅은 set_name() 의 3번째 인자로 
		// lvalue 를 보내면 lvalue 캐스팅 - 복사 생성자 호출
		// rvalue 를 보내면 rvalue 캐스팅 - 이동 생성자 호출
		name = std::forward<T>(n);	// 3. 정답
	}
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








