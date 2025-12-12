// Step3. 모든 요소 보관하기 

template<typename ... Types>
class tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value{ v } {}

	static constexpr int N = ?;
};

int main()
{
	tuple<> t0;						// 보관하는 요소 없음
	tuple<             short> t1;	// short 만 보관
	tuple<     double, short> t2;	// double 만 보관
	tuple<int, double, short> t3;	// int 만 보관
}
