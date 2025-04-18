#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	( std::cout << ... << args );



	// fold expresson �� "pack �̸�" �� �ƴ϶� 
	// "pack �̸��� ����ϴ� ����" �� ��밡��

}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



