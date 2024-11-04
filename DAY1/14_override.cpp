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
	// 가상 함수 재정의시 실수(오타)
	// => 에러가 발생하지 않습니다.
	// => 새로운 함수를 만들었다고 컴파일러가 생각
//	virtual void fooo() {}
//	virtual void goo(double a) {}
//	virtual void hoo() const  {}

	// 위 문제를 해결하기 위해 C++11 에서 "override" 키워드제공
	// => 새로운 함수가 아닌 기반 클래스 함수를 오버라이드 하고 있다고
	//    알려주는것
	// => 오타 발생시 에러
	virtual void fooo()        override {}
	virtual void goo(double a) override {}
	virtual void hoo() const   override {}
};


int main()
{
}
