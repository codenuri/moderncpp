

int main()
{
	// generic lambda
	// => 인자로 auto 를 사용하는 람다 표현식
	// => c++14 부터 지원
	auto f = [](auto a, auto b) { return a + b; };

	int    n = f(1, 2);
	double d1 = f(3.2, 3.2);
	double d2 = f(3.2, 1);
}
// generic lambda 의 원리
class CompilerGeneratedName
{
public:
	// 핵심 : 2개의 인자가 서로 다른 템플릿
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
/*
// 람다가 아닌 일반 함수의 인자로 auto 를 사용할수 있을까요?
// => C++20 부터 됩니다.
auto add(auto a, auto b)
{
	return a + b;
}
auto ret1 = add(1, 2);
auto ret2 = add(1.2, 2);

// 위 add 는 template 입니다. 아래와 동일
template<typename T1,typename T2>
auto add(T1 a, T2 b)
{
	return a + b;
}
*/