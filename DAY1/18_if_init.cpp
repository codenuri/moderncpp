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
	// legacy if :  if ( ���ǽ� )
	// ���ο� if :  if ( �ʱ�ȭ����; ���ǽ� )
	if (int ret1 = foo(); ret1 == 0)
	{

	}	//<== ret1 �ı�!! ���� ������ʹ� �ٽ� ret1 ���� ����


	// switch �� �����մϴ�.
	switch (int n = foo(); n)
	{
	case 1: break;
	case 2: break;

	}

}