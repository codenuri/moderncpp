// 7_�����ڻ��1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:

	// #1. �����ڴ� ��ӵ��� �ʴ´�
	// #2. C++11 ���ʹ� "����ش޶�"�� ��û�Ҽ� �ֽ��ϴ�.
	using Base::Base;  // using Ŭ�����̸�::�������̸�
};

int main()
{
	// �Ʒ� 2���� ������ ������
	Derived d1;
	Derived d2(5);
}
