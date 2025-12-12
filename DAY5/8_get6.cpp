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
// => 결국 primary 버전은 사용되지 않습니다.
// => 제거할수는 없고, 선언만 제공하면 됩니다.
template<int N, typename TP>
struct tuple_element;

// N == 0
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
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

template<int N, typename TP>
typename tuple_element<N,TP>::type &
get(TP& tp)
{
	return static_cast<typename tuple_element<N, TP>::tupleType&>(tp).value;
}

int main()
{
	tuple<int, double, short> t{ 1, 3.4, 'A' };

	get<1>(t) = 1.1;

	std::cout << get<1>(t) << std::endl; // 1.1
	std::cout << get<0>(t) << std::endl; // 1
}
