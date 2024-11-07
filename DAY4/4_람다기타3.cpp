int main()
{
	// generic lambda - C++14
	// => 2개의 인자가 서로 다른 템플릿 인자이므로
	// => 아래 코드가 swap(int, double)로 사용해도 에러가 아닙니다.
//	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
//										   a = std::move(b); 
//										   b = std::move(tmp); };

	// template lambda expression - C++20
	// => 위와 같은 문제를 해결하기 위해 도입
	// => template lambda 가 있으면 위 문법은 없어도 되지만, 먼저 나온 문법
	auto swap = []<typename T> (T& a, T& b) { T tmp = std::move(a);a = std::move(b); b = std::move(tmp); };


	int n = 10;
	double d = 3.4;

	swap(n, d); // 에러가 없는게 좋을까요 ? 에러가 있는게 좋을까요 ?
}
