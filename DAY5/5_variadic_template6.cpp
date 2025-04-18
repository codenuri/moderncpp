#include <iostream>

// �������� ���ø��� ���� ����ϳ��� ??
// => �ʿ��� �������� ��찡 �ֽ��ϴ�. �׶��� ����ϸ� �˴ϴ�.

// #1. �Ϻ��� ����
// #2. tuple ���� ���� ���鶧.. 



void foo(int a, int b, int& c) { c = 100; }

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
//	return f( std::forward<T>(arg...)); // std::forward �� 3������ ��� ����
	return f(std::forward<T>(arg)...); 
			// f( std::forward<T1>(E1), 
			//	  std::forward<T2>(E2), std::forward<T3>(E3))
}

int main()
{
	int n = 10;

	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

