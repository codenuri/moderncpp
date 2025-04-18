#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	( std::cout << ... << args );



	// fold expresson 은 "pack 이름" 뿐 아니라 
	// "pack 이름을 사용하는 패턴" 도 사용가능

}

int main()
{
	Show(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}



