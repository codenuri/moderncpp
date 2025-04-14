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
	void foo()      override final {} 
	void goo(int a) override {}
	void hoo()      override {}
};
class Derived2 : public Derived
{
public:
	void foo()      override final {} // error. final!!
	void goo(int a) override {}	// ok
	void hoo()      override {} // ok
};


int main()
{
}