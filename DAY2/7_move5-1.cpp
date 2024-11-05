#include <iostream>

// std::move() - 100 page

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

//	Cat c2 = c1;				// 복사 생성자 호출
//	Cat c3 = std::move(c1);		// 이동
//	Cat c4 = static_cast<Cat&&>(c1);	// 이동

	Cat c5 = foo(); // 결과가 예상과 다른 이유
					// "ellision copy" 라는 최적화 때문에. 
}

// g++ 의 "-fno-elide-constructors" 라는 옵션을 사용하면
// => (복사, move) 생성자를 호출하지 않은 최적화를 제외할수 있습니다.

// godbolt.org
// =>위코드 붙여넣기 하세요


