// 18_if_init    49 page

int foo() { return 100; }

int main()
{
	// #1. C/C++ ���� ���� ���� ����ϴ� �������� �ڵ�
	int ret = foo();

	if (ret == 0)
	{
	}

	// #2. �� #1 �� C++17 ���� �Ʒ� ó�� ��밡���մϴ�.
	if (int ret1 = foo(); ret1 == 0)
	{

	}

}