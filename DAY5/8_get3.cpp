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
//	using type = 튜플 TP 에서 N 번째 요소의 타입을 type;
	
	// primary 버전에서는 구할수 없습니다.
	// "구할수 있게 부분 특수화를 만드는 것이 핵심"
};

// N == 0 일때의 부분 특수화
/*
template<typename TP>
struct tuple_element<0, TP>
{
	using type = TP의 0번째요소타입;

	// 아직 구할수 없다. 잘못된 부분특수화
};

template<typename ... Types>
struct tuple_element<0, tuple<Types...> >
{
	using type = tuple<Types...> 의 0번째요소타입;

	// 역시 못 구함. 잘못된 부분 특수화
};
*/

// 핵심
// 1. N == 0 인 경우로 고정하고
// 2. TP 라는 타입에서 tuple 의 0번째 요소가 코드에 나타나도록
//   tuple<T, Types...> 으로 부분 특수화

template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;

};







template<typename TP>
void foo(TP& tp)
{
	// 현재 TP : tuple<int, double, short>

	typename tuple_element<0, TP>::type d; // 만들어 봅시다.

	std::cout << typeid(d).name() << std::endl; // int
}


int main()
{
	tuple<int, double, short> t{ 1, 3.4, 'A' };

	foo(t);
}
