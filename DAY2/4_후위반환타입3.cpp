#include <iostream>

/*
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}

*/
// decltype : ? ���� ��ġ�� ����Ϸ��� ���� �ڵ�
// �׷��� �Ʒ� �ڵ尡 ���� �Դϴ�.
template<typename T1, typename T2>
decltype(a * b) Mul(T1 a, T2 b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1) << std::endl;

	a = 10; // error. ������ ���� ���� ���
	int a = 0;
	a = 10; // ok
}

