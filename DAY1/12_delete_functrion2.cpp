#include <iostream>

// gcd(int) ������ �ִµ�, gcd(�Ǽ�)�� �����ϸ�

// gcd(double) ������ ������ : gcd(int) ���� ȣ��
//		=> �ٽ� gcd(double)�� ������ �Ͻ��� ����ȯ�� ���� gcd(int) ȣ��

// gcd(double) ������ ���� ������ : "��ũ" ����
//		=> �Ʒ� �ҽ��� ���������� �ƴ� ������� ó�� ���� �Ǹ�
//		=> ��ŷ ���� �����Ƿ� "gcd(�Ǽ�) ȣ��" �� ���� �ƴ�.

//  gcd(double) ������ ���� �Ǿ����� : "������" ����
//--------------------------------------------------------

//double gcd(double a, double b); // �ٽ� : ����!!

double gcd(double a, double b) = delete; // �Ϲ� �Լ� �� ��������



int gcd(int a, int b)
{
	// a, b�� �ִ� �����(gcd)��ȯ .. ���� ����
	return 0;
}

int main()
{
	auto ret1 = gcd(10, 3);
	auto ret1 = gcd(3.3, 3.2);
}

