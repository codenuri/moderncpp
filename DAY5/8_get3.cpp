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

template<typename TP>
void foo(TP& tp)
{
	// 현재 TP : tuple<int, double, short>

	typename tuple_element<1, TP>::type d; // 만들어 봅시다.

	std::cout << typeid(d).name() << std::endl; // double
}

int main()
{
	tuple<int, double, short> t{ 1, 3.4, 'A' };
}
