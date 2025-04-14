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
	// final : ���̻� override �Ҽ� ����.
	// => ���̺귯�� ���ο����� override �ϰ�
	// => ���̺귯�� ����ڴ� override �Ҽ� ���� �Ҷ� ���� ���
	void foo()      override final {} 
	void goo(int a) override {}
	void hoo()      override {}
};
// Ŭ���� �̸��ڿ� final : ��ӹ����� ����.
class Derived2 final : public Derived
{
public:
	void foo()      override final {} // error. final!!
	void goo(int a) override {}	// ok
	void hoo()      override {} // ok
};

class Derived3 : public Derived2 {}; // error
									// Derived2 �� final Ŭ����

int main()
{
}