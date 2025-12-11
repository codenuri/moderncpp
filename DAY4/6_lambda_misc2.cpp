//void foo(auto n) {} 

int main()
{
	// generic lambda
	auto f1 = [](int a, int b) { return a + b; };

	int    n = f1(1, 2);			// ok. 결과는 3
	double d = f1(3.2, 3.2);		// ok. 결과는 6

	//-----------------------------------------------
	// generic 람다
	// => 람다 표현식인자로 auto 를 사용하는 기술
	// => C++14 부터 지원
	auto f2 = [](auto a, auto b) { return a + b; };

	int    n = f2(1, 2);			// ok. 결과는 3
	double d1 = f2(3.2, 3.2);		// ok. 결과는 6.4
	double d2 = f2(3,   3.2);		// ok. 6.2

}

// geneic lambda 의 원리
// => 2개의 인자가 다른 템플릿 인자 라는 것이 핵심
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	inline auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
