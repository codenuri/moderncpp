// Step2. 한개 요소 보관하기 

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;  
};

// template 인자가 한개이상인 경우를 위한 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple( const T& v) : value(v) {}

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;
	tuple<short> t1;				// short  보관
	tuple<double, short> t2;		// double 만 보관
	tuple<int, double, short> t3;	// int    만 보관
}