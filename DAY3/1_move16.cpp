#include <iostream>
#include <string>
#include <vector>

class People
{
private:
	std::string name;
	int age;

public:
	// move 지원 setter 만드는 법

	// 방법 #1. 2개의 함수 사용
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n) { name = std::move(n); }


	// 방법 #2. T&& 사용.
	template<typename T>
	void set_name(T&& n)
	{
//		name = n;					// 1. 항상 복사
//		name = std::move(n);		// 2. 항상 이동
		name = std::forward<T>(n);	// 3. lvalue 를 보내면 lvalue 캐스팅(복사)
									//    rvalue 를 보내면 rvalue 캐스팅(이동)
	}

	// 방법 #1. set_name(const std::string& n) 이 함수가
	// => lvalue, const lvalue 를 모두 해결한다.

	// 방법 #2 는
	// => set_name(std::string& n) 도 생성하고
	// => set_name(const std::string& n) 도 생성


	// 그래서 보통, 방법 #1 을 권장합니다.
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// T&& : string&	
	p.set_name(std::move(s2));	// T&& : string&&

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
}








