#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& arg) {}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{

//	f(static_cast<T&&>(arg));	// �̷��� ����ص� �˴ϴ�.
								// ��Ȯ�� �ڵ� �Դϴ�.

	// �׷���, C++ ǥ�ؿ����� ���� ������ ĳ������ �����ϴ�
	// std::forward �� �����մϴ�.

	f(std::forward<T>(arg)); // �� �ڵ�� ������ ����
							 // ��, T&& �� �ƴ� T �� �����ؾ� �մϴ�.
							 // ���������� && �� �ٿ��� ĳ�����մϴ�.
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	

	chronometry(goo, n);	

}
