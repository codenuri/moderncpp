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
	using type = T;

};

// N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	// tuple<int, double, short>  의 2번째 요소 타입 short
	// tuple<     double, short>  의 1번째 요소 타입 short
	// tuple<             short>  의 0번째 요소 타입 short

	using type = typename tuple_element<N-1, tuple<Types...> >::type;

};






template<typename TP>
void foo(TP& tp)
{
	// 현재 TP : tuple<int, double, short>
	typename tuple_element<1, TP>::type d; 

	std::cout << typeid(d).name() << std::endl; 
}


int main()
{
	tuple<int, double, short> t{ 1, 3.4, 'A' };

	foo(t);
}
