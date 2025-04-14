#include <iostream>
#include <concepts>

// ���� �迭 Ÿ���� �ƴ� ��� Ÿ�� ������ gcd�� ���� �ش޶�.
// => C++20 �� concept ��� ��� ( 5���� �ڼ��� ����)
template<typename T> requires (!std::integral<T>)
T gcd(T a, T b) = delete; 

// ��, int ������ ����
int gcd(int a, int b)
{
	return 0;
}

int main()
{
	auto ret1 = gcd(10, 3);
//	auto ret2 = gcd(3.3, 3.2);
//	auto ret3 = gcd(3.3f, 3.2f);

	short s = 1;
	auto ret2 = gcd(s, s);
}

