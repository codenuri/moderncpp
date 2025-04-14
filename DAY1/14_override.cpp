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
	// ���� �Լ� �����ǽ� �Ǽ�(��Ÿ) �� �־
	// => ������ �ƴմϴ�.
	// => �ٸ� �����Լ��� �߰��ߴٰ� �����Ϸ��� ���� 
//	virtual void fooo() {}
//	virtual void goo(double a) {}
//	virtual void hoo() const  {}

	// C++98 ������ ���� ���� Ư¡ ������ ���װ� �ʹ� ���� ������ϴ�.
	// => �׷��� C++11 ���� override Ű���� �߰�
	// => ���ο� �Լ��� �ƴ� "�������̵�" �ϴ� ���̶�� �˸��°�
	virtual void fooo() override {}
	virtual void goo(double a) override {}
	virtual void hoo() const override {}


};


int main()
{
}