#include <iostream>

void foo(int a) {}


// �ٽ� ����
// �Ϻ��� ���� ����� ����Ϸ��� 
// #1. ���ڸ� �������� T&& �� ��������
// #2. ���� ���ڸ� �ٸ����� �������� "std::forward<T>(arg)" �� ��� ���� ����

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg)); 
}

int main()
{
	chronometry(foo, 10);


}
