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
	// final : 더이상 override 할수 없다.
	// => 라이브러리 내부에서만 override 하고
	// => 라이브러리 사용자는 override 할수 없게 할때 많이 사용
	void foo()      override final {} 
	void goo(int a) override {}
	void hoo()      override {}
};
// 클래스 이름뒤에 final : 상속받을수 없다.
class Derived2 final : public Derived
{
public:
	void foo()      override final {} // error. final!!
	void goo(int a) override {}	// ok
	void hoo()      override {} // ok
};

class Derived3 : public Derived2 {}; // error
									// Derived2 는 final 클래스

int main()
{
}