// �Ʒ� �ڵ尡 �� �������� ������ ������ ?
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error. int ������ * �����Ҽ� ����.
	}
};

int main()
{
	A a;
}
*/

template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10; 
	}
};

int main()
{
	A a;
}
