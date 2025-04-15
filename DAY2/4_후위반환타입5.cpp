#include <iostream>

// #1. ���� Ÿ���� ������ �ڵ� �Դϴ�.
// => "return �������� ��ȯŸ���� �߷��ش޶�" �� ��
// => C++14 ���� ����
// 1. 2�� �̻��� return ���� �ְ� "���� �ٸ� Ÿ��"�� ��ȯ�ϸ� error
// 2. "return exp" ���� exp �� ���� Ÿ���̾ ������ ��ȯ
//		(auto �߷��̹Ƿ�)
template<typename T1, typename T2>
auto Mul1(T1 a, T2 b)
{
	if (b == 1) return a;
	return a * b;
}
// Mul1(1, 3.4)



// #2. �Ʒ� �ڵ�� ��ȯ Ÿ���� ǥ���Ѱ�
// => C++11 ���� ��밡��
// => return ������ ������ �̰�, ���� �ٸ� Ÿ���� ��ȯ�ص�
// => return Ÿ���� "decltype(a*b)"
// => decltype(exp) ���� exp �� ������� ��ȯ Ÿ�Ե� ����
//    auto �� ���� ���� ���� ���� ����. 

template<typename T1, typename T2>
auto Mul2(T1 a, T2 b) -> decltype(a* b)
{
	if (b == 1) return a;  
	return a * b;
}

// #3. return �������� �߷��ش޶�°�
// => ��, auto ����� �ƴ� decltype ���
// => return ������ 2�� �̻� �̰� ���� �ٸ� Ÿ������ ��ȯ�ϸ� error
// => C++14
template<typename T1, typename T2>
decltype(auto) Mul3(T1 a, T2 b) 
{
	return a * b;
}

// ���
// 1. ���Ϲ����� �Ѱ���� : auto, decltype(auto) �� ���� �ڵ�
// 2. ���� ������ ������ �̰ų�, ��Ȯ�� ǥ���Ϸ���
//    => Mul2 ó�� ����ϴ� ���� ����



int main()
{

}

