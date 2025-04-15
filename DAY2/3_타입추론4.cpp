#include <iostream>

// ��Ģ #2. ���ڰ� ���� Ÿ�� �϶�
// => �Լ� ������ reference �Ӽ��� �����ϰ� Ÿ�� ����
// => const, volatile �Ӽ��� ���� 
template<typename T> void foo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// T �� a �� Ÿ���� ���� �����ؼ� �����ؾ� �մϴ�.
	foo(n);		// T = int		a = int&
	foo(c);		// T = int	    a = int& �� �����ϸ� int& a = c �ε�. error
				// T = const    a = const int& �� ����!! <= ���� ���� ������!
	
	foo(r);		// T = int			a = int&
	foo(cr);	// T = const int	a = const int& 	
}