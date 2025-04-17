// �Ϻ�������_���ǻ���
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg) // int&& arg = 0
{
	f(std::forward<T>(arg));	// foo(arg)
}

void foo(int* p) {}

int main()
{
	foo(0); // ok

	chronometry(foo, 0); // foo(0) �ش޶�� ��
						 // �׷���, error

	chronometry(foo, nullptr); // ok

}

// �Ϻ��� ���� ���
// => ���ڸ� �����Ҷ� �߰����� ���ļ� �����ϴ� ��
// main ==> chronometry ==> foo

// ������ �ǹ��� 0 �� ����Ҽ� �����ϴ�.
// => nullptr ����ϼ���








