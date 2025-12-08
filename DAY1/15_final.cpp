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
	// final : 현재 까지만 override 가능하고, 이후 파생클래스는 override 안됨
	virtual void foo()      override final {} 
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

// 클래스이름 뒤에 final : 더이상 상속에 사용될수 없다.
class Derived2 final : public Derived
{
public:
	virtual void foo()      override {} // error
	virtual void goo(int a) override {} // ok
};
class Derived3 : public Derived2  // error
{}; 

int main()
{
}