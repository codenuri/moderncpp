#include <iostream>

int& foo(int& a, double d, char c) { return a; }

void hoo() {}

// �Ϻ��� ���� �߰�
// ������ ���� ���� ����
// => C++11 �� variadic template(5���� ����)

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg) 
{
	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 0;

	chronometry(hoo);    // ���ڰ� ���� �Լ�
	chronometry(foo, n, 3.4, 'A'); // ���ڰ� 3���� �Լ�
}
