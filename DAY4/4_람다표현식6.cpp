// 145 page
#include <iostream>

int main()
{
	// ����ǥ������ ��Ȯ�� ���
	// => ���� ��ȯ Ÿ������ ���� Ÿ�� ǥ��
	auto f1 = [](int a, int b) -> int { return a + b; };

	// return �������� ��ȯ Ÿ�� �߷��� ������ ��� ���� ����

	auto f2 = [](int a, int b)  { return a + b; }; // ok


	auto f3 = [](int a, int b)  { if (a == 0) return b;  return a + b; };

	// �Ʒ� �ڵ�� 2�� �̻��� return ������ �ٸ� Ÿ���� ��ȯ�ϹǷ�
	// �ݵ�� ��ȯ Ÿ�� ǥ���ؾ� �մϴ�.
	// ǥ������ ������ ����. 
	auto f4 = [](double a, int b) { if (a == 0) return b;  return a + b; };

}

