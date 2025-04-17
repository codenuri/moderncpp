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
	auto f1  =   [](int a, int b) { return a + b; }; // ok

	auto& f2 =   [](int a, int b) { return a + b; }; // error
											// lvalue reference ��
											// rvalue �� ����ų�� ����

	const auto& f3 = [](int a, int b) { return a + b; }; // ok

	auto&& f4 = [](int a, int b) { return a + b; }; // ok

	// T&&

	// auto && �� T&& �Դϴ�.(forwarding reference)
	// => ���� lvalue, rvalue ��� ����ų�� �ֽ��ϴ�.
	auto&& a1 = 10; // ok.  int&& a1 = 10
	auto&& a2 = n;  // ok.  int&  a2 = n;
}

