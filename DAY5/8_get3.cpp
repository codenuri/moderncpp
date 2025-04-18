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
	// TP ���� N ��° ��� Ÿ���� ���ؼ� ? ä���� �մϴ�.
//	using type = ? 
	
	// ����� ���Ҽ� �����ϴ�.
	// Ÿ���� ���Ҽ� �ֵ��� �κ� Ư��ȭ �ؾ� �մϴ�
};

// N == 0 ���� �κ� Ư��ȭ
/*
template<typename TP>
struct tuple_element<0, TP>
{
	// TP ���� 0 ��° ��� Ÿ���� ���ϸ� �˴ϴ�.
	// => ������ ���Ҽ� �����ϴ�. �߸��� �κ�Ư��ȭ �Դϴ�.
	using type = ? ;

};
*/
/*
template<typename ... Types>
struct tuple_element<0, tuple<Types...> >
{
	// ���� "tuple<Types...>" ���� 0 ��° Ÿ���� ���Ҽ� �����ϴ�.
	// => �߸��� �κ� Ư��ȭ
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
	// ���� TP : tuple<int, double, short> �Դϴ�.

	typename tuple_element<0, TP>::type n1; // int n1 �Ǿ� �մϴ�.
//	typename tuple_element<1, TP>::type d1; // double d1 �Ǿ� �մϴ�.

	std::cout << typeid(n1).name() << std::endl;
}

int main()
{
	tuple<int, double, short> t(1, 3.4, 3); 
	
	test(t);
}

