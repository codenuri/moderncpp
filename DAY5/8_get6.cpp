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

// Rust, swift, python 는 tuple 사용이 아주 간단합니다.
// rust 코드
//let tp = (1, 3.4, 'A');

//let n = tp.0;  // get<0>(tp)

// C++ 은 왜 사용법이 복잡한가요 ?

// Rust, swift, python : tuple 이 언어의 스펙에 있는 언어의 일부. 
// C++ : tuple 은 라이브러리, 컴파일러가 인식하는 타입이 아님.

// C++ 
// => 만들수 있다면 절대 언어는 변경하지 않는다. (호환성 문제)
// => 만들수 없는 것만 언어를 변경한다.

// 그래도, 불편합니다.
// => structure binding 사용해라
//auto [a, b, c] = tp;

// C++ 표준 tuple
// => tuple 요소의 메모리 순서는 보장하지 않는다. => 최적화된 구현을 위해서
// => 하지만, get<> 으로 꺼내오는 순서는 보장한다.
//    get<0>(tp) 는 항상 1번째 이다.