#include <iostream>

// auto �� ���� ǥ����
int main()
{
	// ���� ǥ������ auto ������ ��Ƽ� �Լ� ó�� ��밡��
	// ( ��Ȯ���� ����ǥ������ ���� �ӽð�ü�� f�� ���� �ؼ� ����ϴ°�)

	auto f = [](int a, int b) { return a + b; };	
			// class xxx{operator()(int a, int b){}}; xxx{};

	// ���� f �� �Ϲ� �Լ�(�ζ���)ó�� ����ϸ� �˴ϴ�.
	int n = f(1, 2); 
	//------------------------------------------
	// ������ ã������
	auto f1  =   [](int a, int b) { return a + b; };
	auto& f2 =   [](int a, int b) { return a + b; };

	const auto& f3 = [](int a, int b) { return a + b; };

	auto&& f4 = [](int a, int b) { return a + b; };
}

