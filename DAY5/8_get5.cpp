// get3.   tuple5 복사. 
#include <iostream>

//=====================================================================
template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;
	T value;

	tuple() = default;
	tuple(const T& v, const Types& ... args)
		: value{ v }, base{ args... }
	{
	}
	static constexpr int N = base::N + 1;
};
// =============================================================
// primary template
template<int N, typename TP>
struct tuple_element
{
};

// N == 0
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	// tuple<T, Types...> 에서 0번째 타입은      ?  T
	// tuple<T, Types...> 에서 0번째를 보관하는 타입 ?tuple<T, Types...>
	using type = T;

	using tupleType = tuple<T, Types...>;
};

// N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple<Types...> >::type;
	using tupleType = typename tuple_element<N - 1, tuple<Types...> >::tupleType;

};






template<typename TP>
void foo(TP& tp)
{
	// 현재 TP : tuple<int, double, short>
	typename tuple_element<1, TP>::tupleType d;

	std::cout << typeid(d).name() << std::endl;
}


int main()
{
	tuple<int, double, short> t{ 1, 3.4, 'A' };

	foo(t);
}
