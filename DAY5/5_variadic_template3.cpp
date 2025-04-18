#include <iostream>

// parameter pack, sizeof...

template<typename ... Types> void foo(Types ... args)
{
	// #1. "parameter pack" �̶�� ��� �˾� �μ���
	// 
	// Types : int, int, int	=> template parameter pack
	// args  : 1, 2, 3			=> function parameter pack


	// #2. sizeof... : pack �ȿ� �ִ� ����� ���� ����

	std::cout << sizeof...(Types) << std::endl; // 3
	std::cout << sizeof...(args)  << std::endl; // 3
}





int main()
{
	foo(1, 2, 3); // void foo(int, int, int) �Լ� �����˴ϴ�.
}