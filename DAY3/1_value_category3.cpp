#include <iostream>
#include <type_traits>

// decltype(expression)
// => expression �� result �� �����ϴ� ����
// => type �� value category ����

// expression �� lvalue ��� : ���� Ÿ��
// expression �� rvalue ��� : �� Ÿ��
int main()
{
	int n = 0;

	n * 3 + 2;

//	using T = decltype(n * 3 + 2);
//	using T = decltype(n); // �̷��������ϸ� ��Ģ #1 ���
						   // lvalue, rvalue ���簡 �ƴ϶� �������� ����
	using T = decltype((n)); // ��Ģ #2�� ����ϰ� �ϱ� ����
							//  expression �� () �� ������

	if (std::is_lvalue_reference_v<T>) // T �� �������� �����ϴ°�
	{
		std::cout << "lvalue\n";
	}
	else
	{
		std::cout << "rvalue\n";
	}
}
// ��� ���� C++17�� �����ϰ� ������ ������. 