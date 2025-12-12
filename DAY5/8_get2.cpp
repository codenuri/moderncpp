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
		: value{ v }, base{ args... }
	{
	}
	static constexpr int N = base::N + 1;
};

int main()
{
	tuple<> t0;						// 보관하는 요소 없음
	tuple<             short> t1;	// short 만 보관
	tuple<     double, short> t2;	// double 만 보관
	tuple<int, double, short> t3;	// int 만 보관

	tuple<int, double, short> t{ 1, 3.4, 'A' };

	// 아래 ? 채우세요
	std::cout << t.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short>&>(t).value << std::endl; // 3.4

	std::cout << static_cast<tuple<short>&>(t).value << std::endl; // 65


	double d = get<1>(t);

//	get<1>(t) = 1.1;
}

// get 의 모양
template<int N, typename TP> 
튜플TP의 N번째 요소의 타입&
get(TP& tp)
{
	return static_cast<TP의N번째부모의타입&>(tp).value;
}

// 결국 get을 구현하려면 2개를 알아야 합니다.
// TP 가 튜플 일때

// 1. TP 의 N 번째 요소의 타입
// 2. TP 의 N 번째 부모의 타입

// => 결국 타입구하기가 핵심









