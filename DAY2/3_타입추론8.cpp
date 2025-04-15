// decltype Ÿ�� �߷� - 71page

// decltype(expression)
// => () �ȿ� �ִ� ǥ�������� Ÿ�� �߷�
// => ǥ������ ����� lvalue ���� rvalue ���� �� ���� �޶���(�����ϴ� ����)

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// ��Ģ #1. () �ȿ� ���� �̸��� ������(id - expression)
	// => ������ ������ ���� Ÿ�� ����

	decltype(n) d1; // int d1
	decltype(r) d2; // int& d2  �ε�,  ���� �ڵ�� �ʱⰪ ���� ������ ����
	decltype(c) d3; // const int d3    ���� �ڵ�� �ʱⰪ ���� ������ ����
	decltype(p) d4; // int* d4


	// ���� �Ʒ� ������ �˾� �μ���
	auto a5 = c;		// int a5 = c;
	decltype(c) d5 = c;	// const int d5 = c;
}