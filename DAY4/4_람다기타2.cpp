// C++14 부터 람다표현식의 인자로 auto 사용가능합니다.

// 일반 함수 인자로 auto 사용될까요 ?
// => C++20 부터 됩니다.
void foo(auto n) {}		// template<typename T>
						// void foo(T n) {}

// auto add(auto a, auto b) { return a + b; }

int main()
{
	// generic lambda
	// => 인자로 auto 를 사용하는 람다표현식, C++14에서 도입
	auto f = [](auto a, auto b) { return a + b; };

	int    n = f(1, 2);
	double d1 = f(3.2, 3.2);
	double d2 = f(3.2, 3);
	double d3 = f(3,   3.2);
}

// generic lambda 원리
// => template
// => 핵심 : 2개의 인자가 서로 다른 타입인자.
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	inline auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
