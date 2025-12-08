#include <iostream>

template<typename T>
class Base
{
public:
	virtual void foo(const T p)
	{
		std::cout << "Base foo\n";
	}
};

class Derived : public Base<int*>
{
public:

	// void foo(const T p)    : p 가 const 라는 의미
	// void foo(const int* p) : p 가 가리키는 것이 const 라는 의미. p는 const 아닙
	// void foo(int* const p) :  이코드가 p가 const 
	// 
	// foo() 가상함수 재정의 하세요. - override 키워드 사용하지 말고 해보세요
	// => 아래 코드는 Base foo 재정의 한것 아닙니다.
	// => 새로운 함수 만들것.
	// => override 붙였다면, 잘못된것을 컴파일 시간에 알수 있지만,,
	// => override 안 붙였다면, 잘못된것을 찾기 어렵게 되고, 버그로 연결
	//virtual void foo(const int* p) override // 잘못된 오버로딩
	virtual void foo(int* const p) override   // 이게 맞는 코드
	{
		std::cout << "Derived foo\n";
	}

};


int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" 나오게 해보세요. 
}