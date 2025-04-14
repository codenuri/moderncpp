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
	// 가상 함수 재정의시 실수(오타) 가 있어도
	// => 에러는 아닙니다.
	// => 다른 가상함수를 추가했다고 컴파일러가 생각 
//	virtual void fooo() {}
//	virtual void goo(double a) {}
//	virtual void hoo() const  {}

	// C++98 시절에 위와 같은 특징 때문에 버그가 너무 많이 생겼습니다.
	// => 그래서 C++11 부터 override 키워드 추가
	// => 새로운 함수가 아닌 "오버라이드" 하는 것이라고 알리는것
	virtual void fooo() override {}
	virtual void goo(double a) override {}
	virtual void hoo() const override {}


};


int main()
{
}