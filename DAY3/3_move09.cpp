#include <iostream>
#include <cstring>
#include <string>

// rule of 0
// => 복사/이동 모두 만들지 않은 것이 best 이다!!!

// 자원을 직접 관리하지 말고, 자원 관리 객체에 의존해라!!
// char* => std::string
// int* => std::vector 또는 스마트 포인터...

// 자원관리는 직접하지 말고, 해당 자원을 관리하는 클래스를 사용하면
// => 이동과 복사를 모두 만들 필요 없다.
// => 컴파일러가 모두 지원하는 완벽한 클래스!!!


class Cat
{
//	char* name;
	std::string name;

	int   age;
public:
	Cat(const std::string& n, int a) : name(n), age(a)
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





// 참고
// "이동" 이 필요한 위치에서 "복사" 를 사용해도 문제 없다.
// "복사" 가 필요한 위치에서 "이동" 를 사용할수 없다.
/*
// C++
std::string s1 = "AAA";
std::string s2 = s1;			// 복사가 default
std::string s2 = std::move(s1);	// 이동은 선택!

// => 따라서 이동을 하면 빠를수 있는 위치에서도 그냥 복사해도 에러는 아니다

// RUST 코드
let s1 = String::from("AAA");

let s2 = s1;			// 디폴트가 이동
let s2 = s1.clone();	// 복사는 선택

// => 따라서, Rust 는 이동을 이해 하지 못하면
//    실행되는 코드는 만들수 없습니다.

// C++ : 복사 생성자, 이동생성자를 사용자가 직접 만들어서 원리 파악가능
// RUST : 이동생성자를 사용자가 만드는 개념 없습니다.
//		  모든 타입은 기본적으로 언어에서 이동으로 지원
//		  단, 정수, 실수 타입만 기본 동작 복사.
*/