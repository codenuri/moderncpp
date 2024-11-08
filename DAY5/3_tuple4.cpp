// Step3. 모든 데이타 보관하기

template<typename ... Ts>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Ts>
struct tuple<T, Ts...> : public tuple<Ts...>
{
	T value;

	tuple() = default;

	tuple(const T& value) : value(value) {}

	static constexpr int N = 1;
};


int main()
{
	tuple<> t0;						// 보관 안함. primary template 사용
	tuple<short> t1;				// short  보관
	tuple<double, short> t2;		// double 보관
	tuple<int, double, short> t3;	// int 보관
}
