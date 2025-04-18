#include <iostream>
#include <type_traits>


// if constexpr : C++17 ��� �Դϴ�. C++17 �������� �Ʒ� �ڵ� ����!!
/*
template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/

// C++11, 14 ���

template<typename T> 
std::enable_if_t< std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << "������ " << v << " : " << *v << std::endl;
}

template<typename T> 
std::enable_if_t< !std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << "������ �ƴ� " << v << std::endl;
}



int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

