#include "tuple.h"
#include <iostream>

template<typename TP>
void foo(TP& tp)
{
	// TP : int, double, char
	typename tuple_element<0, TP>::type n1;
	typename tuple_element<1, TP>::type n2;

	std::cout << typeid(n1).name() << std::endl;
	std::cout << typeid(n2).name() << std::endl;
}
int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');
	foo(t3);
}