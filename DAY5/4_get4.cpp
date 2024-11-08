#include "tuple.h"
#include <iostream>


template<int N, typename T>
struct tuple_element
{
};

template<typename T, typename ... Ts>
struct tuple_element<0, tuple<T, Ts...> >
{
	using type = T;
};

template<int N, typename T, typename ... Ts>
struct tuple_element<N, tuple<T, Ts...> >
{
	using type = typename tuple_element<N - 1, tuple<Ts...>>::type;
};








template<typename TP>
void foo(TP& tp)
{
	// TP : tuple<int, double, char>
	typename tuple_element<0, TP>::type n1;
	typename tuple_element<1, TP>::type n2;

	std::cout << typeid(n1).name() << std::endl; // int
	std::cout << typeid(n2).name() << std::endl; // double
}
int main()
{
	tuple<int, double, char> t3(1, 3.4, 'A');
	foo(t3);
}