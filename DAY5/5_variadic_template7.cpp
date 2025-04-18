#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
	// 
	// args �� �ִ� ��� ��Ҹ� ������ �ʹٸ�
	// #1. pack expansion
	int x[] = { args... };

	// #2. recursive ���� ��� - ���� ����

	// #3. C++26 pack indexing
	int n1 = args...[0];
	int n2 = args...[1];

	// #4. C++17 fold expression

}


int main()
{
	foo(1, 2, 3);
}

