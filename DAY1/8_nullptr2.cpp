// 8_nullptr2
#include <iostream>

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)	// int arg = 0; 
{										// std::nullptr_t arg = nullptr;
	f(arg);	// 1. arg �� int ���ٸ� foo(arg) �̹Ƿ� error
			// 2. arg �� std::nullptr_t ���ٸ� arg �� ��� Ÿ���� Ÿ������
			//     �Ͻ��� ����ȯ �ǹǷ� ok
}



void foo(int* p) {}

int main()
{
	int n = 0;
	// #1. �Ʒ� 2�� ���� ��Ȯ�� ���� �ϼ���
	foo(0);	// ok
	foo(n);	// error

	// #2. �Ʒ� �ڵ带 ������ ������

///	forward_parameter(foo, 0); // foo ���� 0�� ������ �޶�
								// ��, foo(0) �ش޶�� ��
								// ������ ������ ����.
	forward_parameter(foo, nullptr); // ok!!!

	// nullptr �� ��������
	// => C++11 ���� "���ڸ� forward"�ϴ� ����� �θ� ����ϴµ�
	// => 0 ���� ��ó�� ������ �߻��Ҽ� �ִ�.
	// => nullptr ���� ���� ����. 
}






