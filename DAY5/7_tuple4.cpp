// Step3. ��� ��� �����ϱ�

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
		: value(v), base(args...) {}

	static constexpr int N = base::N + 1;
};

int main()
{
	tuple<> t0;
	tuple<             short> t1;	// short  ����
	tuple<     double, short> t2;	// double �� ����
	tuple<int, double, short> t3;	// int    �� ����

	tuple<int, double, short> t(1, 3.4, 3); // ok
}