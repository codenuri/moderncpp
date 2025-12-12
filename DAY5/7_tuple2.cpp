// Step1. 가변인자 템플릿 사용

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0; // 저장하는 요소의 갯수
};

int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}
