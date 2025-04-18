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

template<typename TP>
void test(TP& tp)
{
	// ���� TP : tuple<int, double, short> �Դϴ�.

	typename tuple_element<0, TP>::type n1; // int n1 �Ǿ� �մϴ�.
	typename tuple_element<1, TP>::type d1; // double d1 �Ǿ� �մϴ�.
}

int main()
{
	tuple<int, double, short> t(1, 3.4, 3); 
	
	test(t);
}

