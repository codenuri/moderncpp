#include <iostream>
// ���ø����� �߷е� Ÿ���� Ȯ���Ϸ���
// ��� #1. godbolt.org ���� ����� �ڵ� ������ - ����
// ��� #2. �Լ� �̸�(signature ����)���

// ���� : RTTI ����� �������� ������..
//       �Ʒ� foo �Լ� ������ �κ� �ּ� ����!

template<typename T> void foo(T a)
{
	// __func__ : �Լ� �̸��� ���� ��ũ�� (C++ ǥ��)
//	std::cout << __func__ << std::endl;

	// __FUNCSIG__ : signature �� ������ �Լ� �̸�(C++ǥ�ؾƴ�, vs ����)
	// __PRETTY_FUNCTION__ : g++, clang++ ������ ����. 
	// std::cout << __FUNCSIG__ << std::endl;


	// �Ʒ� ����� ���� ������� ������ 
	// => C++ �� RTTI ���
	// => const, volatile, reference �� ����Ҽ� ����.
	std::cout << typeid(T).name() << std::endl;
}


int main()
{
	// #1. Ÿ���� ��������� �����ϴ� ���
	// => ����ڰ� ������ Ÿ���� ���
	foo<const int>(3.4);

	// #2. Ÿ���� ��������� �������� ���� ���
	// => �����Ϸ��� ���ڷ� ���� Ÿ���� �߷�
	foo(10); // T : int
	foo(3.4);// T : double
}