#include <iostream>
#include <type_traits>


// enable_if<true,  Ÿ��>::type => "Ÿ��" 
// enable_if<false, Ÿ��>::type => ::type ����

// enable_if<����, void>::type
// ������ true �̸� : void
// ������ fasle��� : ::type ����


//std::enable_if< std::is_integral_v<T>, T>::type
// => T�� �������       : T
// => T�� ������ �ƴϸ�  : ::type ���� => �Լ� ��������
//							SFINAE �� ���� ���� �ƴϰ�, �ĺ� ����

// ����
// std::enable_if<����, ��ȯŸ��>::type

// ������ �����ϸ� "��ȯŸ��"
// ������ �������� ������ �Լ� ��������, ���� �ƴϰ�, ������� �ʰڴٴ°�

template<typename T> 

//typename std::enable_if< std::is_integral_v<T>, T>::type

std::enable_if_t< std::is_integral_v<T>, T>


gcd(T a, T b)
{
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
	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f);
}