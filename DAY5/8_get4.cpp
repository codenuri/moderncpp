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
// => 사용하지 않더라도 있어야만 부분 특수화 가능
// => 단, 구현을 할 필요없이 선언만 있으면 됩니다.
template<int N, typename TP>
struct tuple_element;


// N == 0 은 아래 부분특수화로 해결
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};

// N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	// tuple<int, double, short> 에서 2번째 요소의 타입은
	// tuple<     double, short> 에서 1번째 타입이고
	// tuple<             short> 에서 0번째 타입입니다.

	using type = typename tuple_element<N-1, tuple<Types...>>::type;
};



template<typename TP>
void test(TP& tp)
{
	// 현재 TP : tuple<int, double, short> 입니다.

	typename tuple_element<0, TP>::type n1; // int n1 되야 합니다.
	typename tuple_element<1, TP>::type d1; // double d1 되야 합니다.

	std::cout << typeid(n1).name() << std::endl;
	std::cout << typeid(d1).name() << std::endl;
}

int main()
{
	tuple<int, double, short> t(1, 3.4, 3);

	test(t);
}

