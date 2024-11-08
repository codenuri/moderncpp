// Step3. 모든 데이타 보관하기

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
//	tuple<short> t1;				// short  보관
//	tuple<double, short> t2;		// double 보관
//	tuple<int, double, short> t3;	// int 보관

	tuple<int, double, short> t3(1, 3.4, 'A');
}
/*
struct tuple_no_argument {};

struct tuple_short : public tuple_no_argument
{
	short value;
};
struct tuple_double : public tuple_short
{
	double value;
};
struct tuple_int : public tuple_double
{
	int value;
};

tuple_int t3; // 3개의 value
*/