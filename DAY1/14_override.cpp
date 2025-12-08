// 14_override  - 44 page

class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived : public Base
{
public:
	// 핵심 : 가상함수 재정의시 "실수(오타)"가 있을때
	// => 에러가 아닙니다.
	// => 컴파일러는 새로운 가상함수를 만든 것으로 판단합니다.
	virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}

	// 위와 같은 문제점을 해결하기 위해 C++11 부터 override 키워드 제공
	// => 반드시 사용하세요..
	// => 새로운 함수가 아니라 기반 클래스 함수 재정의 한다고 알리는 것
	virtual void fooo()        override {}
	virtual void goo(double a) override {}
	virtual void hoo() const   override {}


};


int main()
{
}