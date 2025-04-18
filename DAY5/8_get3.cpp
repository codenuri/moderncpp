#include <iostream>

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
		: value(v), base(args...) {
	}

	static constexpr int N = base::N + 1;
};
//-----------------------------------------

// primary template
template<int N, typename TP>
struct tuple_element
{
	// TP 에서 N 번째 요소 타입을 구해서 ? 채워야 합니다.
//	using type = ? 
	
	// 현재는 구할수 없습니다.
	// 타입을 구할수 있도록 부분 특수화 해야 합니다
};

// N == 0 으로 부분 특수화
/*
template<typename TP>
struct tuple_element<0, TP>
{
	// TP 에서 0 번째 요소 타입을 구하면 됩니다.
	// => 하지만 구할수 없습니다. 잘못된 부분특수화 입니다.
	using type = ? ;

};
*/
/*
template<typename ... Types>
struct tuple_element<0, tuple<Types...> >
{
	// 역시 "tuple<Types...>" 에서 0 번째 타입을 구할수 없습니다.
	// => 잘못된 부분 특수화
	using type = ? ;
};
*/

template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T ;
};

template<typename TP>
void test(TP& tp)
{
	// 현재 TP : tuple<int, double, short> 입니다.

	typename tuple_element<0, TP>::type n1; // int n1 되야 합니다.
//	typename tuple_element<1, TP>::type d1; // double d1 되야 합니다.

	std::cout << typeid(n1).name() << std::endl;
}

int main()
{
	tuple<int, double, short> t(1, 3.4, 3); 
	
	test(t);
}

