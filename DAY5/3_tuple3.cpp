// Step2. data 한개 보관 하기

template<typename ... Ts>
struct tuple
{
	static constexpr int N = 0;
};

// 템플릿 인자가 한개 이상인 경우를 위한 부분 특수화
template<typename T, typename ... Ts>
struct tuple<T, Ts...>
{
	T value;

	tuple() = default;

	tuple(const T& value) : value(value) {}

	static constexpr int N = 1;
};


int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}
