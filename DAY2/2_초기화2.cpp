#include <complex>

int main()
{
	// C++98 : ������ ������ ���� �ʱ�ȭ ����� �ٸ��ϴ�.
	int a1 = 10;
	int b1(10); 
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// C++11 "Uniform Initialization" ����
	// => ��� ������ ������ ������ ������� �ʱ�ȭ �����ϴ�.
	// => ����, �߰�ȣ({}) �ʱ�ȭ(brace-init) ��� �մϴ�.
	int a2{ 10 };
	int x2[2]{ 1,2 };
	std::complex<double> c2{ 1, 2 };

	// = �� �־ �˴ϴ�.
	int a3 = { 10 };
	int x3[2] = { 1,2 };
	std::complex<double> c3 = { 1, 2 };

	// direct initialization : = �� ���� �ʱ�ȭ
	// copy   initialization : = �� �ִ� �ʱ�ȭ
}












