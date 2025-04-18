#include <iostream>
#include <type_traits>


// �ν��Ͻ�ȭ(instantiation)
// => ���ø� => ���� C++ �Լ�(Ŭ����)�� ����� ����

// if : ����ð� ���ǹ�
// => ������ false ��� �ν��Ͻ�ȭ�� ���Եȴ�.

// if constexpr : �����Ͻð� ���ǹ�
// => ������ false ��� �ν��Ͻ�ȭ�� ���Ե��� �ʴ´�.

template<typename T> void printv(const T& v)
{
//	if ( std::is_pointer_v<T> )
	if constexpr (std::is_pointer_v<T>)

		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}


int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

