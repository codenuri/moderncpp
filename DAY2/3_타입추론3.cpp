#include <iostream>

// ��Ģ #1. �Լ� ���ø��� ���ڰ� �� Ÿ�� �϶�
// => �Լ� ȣ��Ŀ� �ִ� ������ "const, volatile, reference" �� �����ϰ� 
//    Ÿ�� ����
template<typename T> void foo(T a)
{
	std::cout << __FUNCSIG__ << std::endl;
	a = 100;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// �Ʒ� �ڵ��� ��� ������ T Ÿ���� ������ ������
	foo(n);  // T = int
	foo(c);  // T = int
	foo(r);  // T = int
	foo(cr); // T = int
}