// Step2. 한개 저장하기

template<typename ... Types>
class tuple
{
	static constexpr int N = 0; 
};

// tuple 사용시 타입을 한개 이상 보낼때를 위한 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;

	tuple(const T& v) : value{ v } {} 

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}
