#include <iostream>
#include <type_traits>

// C++20 �� ������ Ÿ���� �����ϴ� "type traits" ����� ������Ų
// concept ������ ��������ϴ�.
template<typename T>
concept pointer = std::is_pointer_v<T>;

template<typename T>
concept not_pointer = !std::is_pointer_v<T>;

//-------------------------------------------
// �Ʒ� �ڵ尡 enable_if6 �� ������ �ǹ�
/*
template<pointer T> 
void printv(const T& v)
{
	std::cout << "������ " << v << " : " << *v << std::endl;
}

template<not_pointer T>
void printv(const T& v)
{
	std::cout << "������ �ƴ� " << v << std::endl;
}
*/
//-----------------
void printv(pointer auto  v)
{
	std::cout << "������ " << v << " : " << *v << std::endl;
}

void printv(not_pointer auto  v)
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

