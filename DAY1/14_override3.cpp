template<typename T>
class Base
{
public:
	virtual void foo(const int c) {}
	virtual void goo(int* const p) {}
	virtual void hoo(const int* p) {}
};

class Derived : public Base<int*>
{
public:
	// 가상함수 override 시에 "인자 자체의 const" 는 제거될수 있습니다.
	// => 인자 : 함수 안에서 만든 지역변수.
	// => 지역변수 자체의 R/W 속성은 외부 변수와 연결되는 것은 아님.
	virtual void foo(int c) override  {}	// ok
	virtual void goo(int* p) override {}	// ok

	// 하지만 대상체에 대한 const 속성은 유지되어야 합니다.
	// => 대상체에 에 대한 const 속성을 외부 변수를 읽기만 하겠다는것.
	// => override 시에 const 를 제거하는 것은 외부 변수를 읽기만 하기위한 함수가
	// => 갑자기 쓰기도 하겠다고 변경한것.. 허용 안됨
	virtual void hoo(int* p) override {}	// error
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);
	p->goo(0);
}