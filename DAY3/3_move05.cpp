// std::move()소개
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	
	Cat c2 = c1;	// c1 은 lvalue,     복사 생성자 호출
	Cat c3 = foo();	// 임시객체는 rvalue, 이동 생성자 호출

	Cat c4 = static_cast<Cat&&>(c2);
					// => lvalue 인 c2 를 rvalue 로 변경해서
					// => 이동생성자를 호출하게 한다.
					// => "c2" 를 더 이상 사용하지 않으므로
					//    자원을 이동해 가라는 의미.

	Cat c5 = std::move(c3); // 이 표준함수가 하는일이
							// 위와 같은 캐스팅

	// 핵심 
	// => "std::move()" 가 자원을 이동하는것 아닙니다!!!

	// 1. std::move 는 단지 인자로 전달된 객체를 "rvalue 로 캐스팅"만 하고
	// 2. 캐스팅 결과로 복사생성자가 아닌 이동생성자가 호출되는 것이고
	// 3. 클래스 안에 이동 생성자가 자원을 이동하는것

	// 결국, move 작업은
	// => 클래스 설계자가 "이동생성자를 만들어서 제공"
}


// 이 분야를 학습할때 "실행결과"가 예상과 다르게 나오는 경우가 많습니다.
// => 컴파일러가 "복사 또는 이동 생성자" 호출을 제거하는 최적화를 하기 때문
// => "copy ellision 이라는 최적화"


// g++ 사용하고, -fno-elide-constructors" 라는 옵션을 사용하면
// => "copy ellision" 하지 말라는 의미 입니다.
// => g++ 소스이름.cpp -std=c++11 -fno-elide-constructors 로 빌드

