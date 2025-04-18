#include <iostream>

// recursive ? - 233page

// 1. 1��° ���ڴ� ������ �̸��ִ� ������ �޴´�.
// 2. ����, ��� ���� ������� ��� ���� ���� 

// ���� : ��¥�� recursive �� �ƴմϴ�
// => foo(3������) => foo(2������) => foo(1������)

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int n = 0;
	++n;

	std::cout << n << value << std::endl;

	if ( sizeof...(args) > 0 )
		foo(args...); // foo(3.4, 'A') => value : 3.4,  args : 'A'
					  // foo('A')	   => value : 'A'   args : ""
				
}

int main()
{
	foo(1, 3.4, 'A'); 
}





