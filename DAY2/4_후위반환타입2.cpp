// ������ȯ - 73 page �Ʒ� �κ�
#include <iostream>

// �Ʒ� ó�� �����
// => 1, 2���ڰ� ���� Ÿ�Ը� �˴ϴ�.
// => Mul(1, 3.4) ���� �ڵ尡 ���� �Դϴ�.
template<typename T1>
T1 Mul(T1 a, T1 b)
{
	return a * b;
}
// �Ʒ� ó�� �����
// => 1, 2 ���ڸ� �ٸ� Ÿ������ �Ҽ� �ֽ��ϴ�. - ���� �Լ� ���ø�
// => �׷��� ? �� ���� �Դϴ�. (�ذ��� ���� �ҽ�)
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

