// ���� �ϴ¹� : Ctrl + F5

int main()
{
	int n1 = 0;

	// auto : �캯�� ǥ�������� �º� ������ Ÿ���� ����
	// => 1. �����Ϸ��� ������ �ð��� ����. �������� ����
	auto a1 = 3;	// int    a1 = 3
	auto a2 = 3.4;	// double a2 = 3.4

	// auto �� �� �����մϴ�.
	const int c = 0;
	auto a3 = c; // 1. int a3 = c;  =>> ����
				 // 2. const int a3 = c;

	// auto �ܿ� decltype �� �ֽ��ϴ�.
	// auto : �캯���� Ÿ�� �߷�
	// decltype() : () ���� ǥ�������� Ÿ���߷�
	decltype(a1) d1; // int d1
}

