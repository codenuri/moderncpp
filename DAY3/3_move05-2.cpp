// std::move()소개
#include <iostream>
#include <cstring>

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

	Cat c2 = c1;			// copy
	Cat c3 = foo();			// move
	Cat c4 = static_cast<Cat&&>(c2);	// move	
	Cat c5 = std::move(c3);	// move
}

// move 를 공부할때 "확인을 위해서 로깅을 해보면"
// => 예상과 다르게 출력됩니다.
// => 컴파일러 최적화 때문에 나타나는 현상


// g++ 로 컴파일 하면서 "생성자 호출을 제거하는 최적화"를 하지 말라는 옵션사용
// g++ 소스이름.cpp -fno-elide-constructors



