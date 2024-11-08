#include <iostream>

template<typename ... Ts>
struct tuple
{
	static constexpr int N = 0;
};
template<typename T, typename ... Ts>
struct tuple<T, Ts...> : public tuple<Ts...>
{
	using base = tuple<Ts...>;

	T value;
	tuple() = default;
	tuple(const T& value, const Ts& ... args)
		: value(value), base(args...) {}

	static constexpr int N = base::N + 1;
};

int main()
{
	//	tuple<> t0;						// 보관 안함. primary template 사용
	//	tuple<             short> t1;	// short  보관
	//	tuple<     double, short> t2;	// double 보관
	//	tuple<int, double, short> t3;	// int 보관

	tuple<int, double, short> t3(1, 3.4, 'A');

	std::cout << t3.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short>&>(t3).value << std::endl; // 3.4 나오게 해보세요

	std::cout << static_cast<tuple<short>&>(t3).value << std::endl; // 'A' 나오게 해보세요

	// get 을 생각해 봅시다.
	auto a = get<0>(t3);

	get<0>(t3) = 30;
}

template<int N, typename TP>
튜플TP타입의 N번째 요소의 타입&
get(TP& tp)
{
	return static_cast<TP의 N번째 부모 타입&>(tp).value;
}

// 위 한글을 코드로 만들면 완성!!
// => 결국, 타입 구하기!!!
// => TP 의 N번째 요소 타입 구하기
// => TP 의 N번째 부모 타입 구하기