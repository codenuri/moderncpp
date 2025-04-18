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

template<int N, typename TP>
struct tuple_element;


// N == 0 �� �Ʒ� �κ�Ư��ȭ�� �ذ�
template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T; // ����� Ÿ��
	using tuple_type = tuple<T, Types...>;// ��Ҹ� �����ϴ� Ʃ�� Ÿ��
};


// N != 0
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple<Types...>>::type;
	using tuple_type = typename tuple_element<N - 1, tuple<Types...>>::tuple_type;
};



template<typename TP>
void test(TP& tp)
{
	// ���� TP : tuple<int, double, short> �Դϴ�.

	typename tuple_element<1, TP>::type n1; //  1��° ����� Ÿ��
	typename tuple_element<1, TP>::tuple_type t1; // 1��° ��Ҹ� �����ϴ�
													//tuple Ÿ��
	std::cout << typeid(n1).name() << std::endl;  // double
	std::cout << typeid(t1).name() << std::endl;  // tuple< double, short>
}

int main()
{
	tuple<int, double, short> t(1, 3.4, 3);

	test(t);
}

