#include <iostream>
#include <type_traits>


// static_assert : ������ �������� ������ ����!!

// �׷���, ������ �����ϸ� ������ �ƴ϶�..
// �ĺ����� ���� �ɼ� ������ ?
// ��, �����̸��� �ٸ� �Լ��� �ִٸ� ��밡���ϵ��� !!!

template<typename T> T gcd(T a, T b)
{
	static_assert (std::is_integral_v<T>, "error not integer");

	return 0;
}
double gcd(double, double)
{
	std::cout << "double\n";
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
	gcd(3.1f, 5.4f);
}