#include <functional>

class Object
{
public:
	void foo(int code) {}		
};
void foo(int n) {}

int main()
{
	// #1. 일반 함수 포인터와 멤버 함수 포인터 만드는 법 알아 두세요
	void(*f1)(int) = &foo;	
	void(Object::*f2)(int) = &Object::foo;


	// #2. 일반 함수 포인터와 멤버 함수 포인터 사용하는 법 알아두세요
	f1(10);       // 일반 함수 포인터 사용
	(obj.*f2)(10);// 멤버 함수 포인터 사용

	// C++ 창시자가 제안했던 "uniform call syntax" 라는 문법
//	f1(10);
//	f2(&obj, 10); //<== 이문법 제안


	// 위문법은 채택되지 않았지만, 
	// C++17 에서 아래 라이브러리 추가
	std::invoke(f1, 10);			// f1(10)
	std::invoke(f2, &obj, 10);		// (obj.*f2)(10)
	
}

