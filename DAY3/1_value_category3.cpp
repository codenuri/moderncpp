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

	using T = decltype(n * 3 + 2);

	if (std::is_lvalue_reference_v<T>) // T �� �������� �����ϴ°�
	{
		std::cout << "lvalue\n";
	}
	else
	{
		std::cout << "rvalue\n";
	}
}
