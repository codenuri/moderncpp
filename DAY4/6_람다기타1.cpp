// 7_���ٱ�Ÿ1 - 150
class Test
{
	int data = 0;
public:
	void foo() // void foo(Test* this)
	{
		// ��� ����Ÿ ĸ�� ?
//		auto f = [](int a) { return a + data; }; // error

//		auto f = [data](int a) { return a + data; }; // error
										// data �� �������� �ƴ�

		// ���� ǥ���� �ȿ��� ��� ����Ÿ�� ����Ϸ��� this �� ĸ���ϸ�˴ϴ�.

//		auto f = [this](int a) { return a + data; }; // ok
										 // this->data �� �ǹ� �Դϴ�.

		auto f = [this](int a) { data = 10; }; // ok. ��� ����Ÿ ���� ����
						// => data �� ĸ���Ѱ��� �ƴ϶�
						// => �ּҸ� ĸ�� �����Ƿ�

	}
}

int main()
{
	Test t;
	t.foo();  // foo(&t)
}

