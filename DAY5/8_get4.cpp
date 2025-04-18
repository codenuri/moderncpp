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
// => ������� �ʴ��� �־�߸� �κ� Ư��ȭ ����
// => ��, ������ �� �ʿ���� ���� ������ �˴ϴ�.
template<int N, typename TP>
struct tuple_element;


// N == 0 �� �Ʒ� �κ�Ư��ȭ�� �ذ�
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};

// N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	// tuple<int, double, short> ���� 2��° ����� Ÿ����
	// tuple<     double, short> ���� 1��° Ÿ���̰�
	// tuple<             short> ���� 0��° Ÿ���Դϴ�.

	using type = typename tuple_element<N-1, tuple<Types...>>::type;
};



template<typename TP>
void test(TP& tp)
{
	// ���� TP : tuple<int, double, short> �Դϴ�.

	typename tuple_element<0, TP>::type n1; // int n1 �Ǿ� �մϴ�.
	typename tuple_element<1, TP>::type d1; // double d1 �Ǿ� �մϴ�.

	std::cout << typeid(n1).name() << std::endl;
	std::cout << typeid(d1).name() << std::endl;
}

int main()
{
	tuple<int, double, short> t(1, 3.4, 3);

	test(t);
}

