class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};
// 가상함수 뒤에 final   : override 할수 없다는 의미
// 클래스 이름뒤에 fianl : 상속받을수 없다 는 의미

class Derived final : public Base
{
public:
	virtual void foo()      override final {} 
								// => 더이상 override 할수 없다.
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

class Derived2 : public Derived
{
public:
	virtual void foo()      override {} // error
	virtual void goo(int a) override {} // ok
	virtual void hoo()      override {} // ok
};
int main()
{
}
