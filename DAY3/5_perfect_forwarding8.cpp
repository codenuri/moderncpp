#include <iostream>

int& foo(int& a) { return a; }


// �Ϻ��� ���� �߰�
// #1. 

template<typename F, typename T>
// auto chronometry(F f, T&& arg)  // return exp �� ����� �����϶�
									// auto �� ������ �����ϰ� �˴ϴ�.
decltype(auto) chronometry(F f, T&& arg) // ok
{
	return f(std::forward<T>(arg));
}

int main()
{
	int n = 0;
	
	int& ret = chronometry(foo, n);

	ret = 100; // �ᱹ n = 100

	std::cout << n << std::endl; // 100 


}
