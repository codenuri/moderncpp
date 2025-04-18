#include <iostream>


template<typename T>
typename T::type foo(T a)  { std::cout << "T" << std::endl; return 0; }
//     int::type foo(int a) { ... }

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	foo(3); // �Լ� ȣ��� ��� �Լ��� ȣ�������� "����"�� ���� ����
			// ����, ���ڵ�� T ������ ����ϱ�� �����ϰ� �˴ϴ�.
			// T = int �� �����˴ϴ�.
			// �׷���, �Լ� ����� "int::type foo(int a)" �� �Ǿ
			// �ν��Ͻ�ȭ�� ���� �߽��ϴ�.
			// => ������ �ƴϰ�, ȣ�Ⱑ���� �����̸��� �ٸ� �Լ��� �ִٸ� ���.

	// Substitution Failure Is Not An Error
	// => SFINAE
}