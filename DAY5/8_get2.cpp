// Step3. 모든 요소 보관하기 

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
	std::cout << t.value << std::endl; // ??

	std::cout << ? << std::endl; // 3.4

	std::cout << ? << std::endl; // 'A'
}
