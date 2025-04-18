#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}


template<typename ... Types> void foo(Types ... args)
{
//	printv(args...);	// printv(E1, E2, E3) �� �ڵ尡 ����
						// printv ���ڴ� �Ѱ��̹Ƿ� error

	printv(args)...; // �ǵ� : printv(E1), printv(E2), printv(E3) 
					 // ������ error

	// �ٽ� : pack expansion ��  ��� ��ġ���� �Ҽ� �ִ°��� �ƴϴ�
	// 1. �Լ� ȣ���� () �ȿ���   : goo( args...)
	// 2. {} �� �ʱ�ȭ �ȿ���     : int x[] = {args...}
	// 3. ���ø� ������ <> �ȿ��� �� ����. : tuple<Types...> 

}


int main()
{
	foo(1, 2, 3);
}

