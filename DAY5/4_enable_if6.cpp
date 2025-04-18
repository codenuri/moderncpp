#include <iostream>
#include <type_traits>


// C++20 ���� template ���鶧 requires clause ��� ���� ���ϼ� �ֽ��ϴ�.
// => enable_if �� �������� ������Ų��

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << "������ " << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v) 
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

