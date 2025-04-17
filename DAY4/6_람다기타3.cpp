int main()
{
	auto swap1 = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	swap1(n, d); // 되는 게 좋을까요 ? 에러 나는게 좋을까요?
				// 에러가 나는게 좋습니다.
				// 그런데, 에러 아닙니다.
				// generic lambda 는 1, 2 인자가 다른 템플릿이 되므로

	// 위 문제를 해결하고
	// 모든 템플릿 기술을 람다 표현식에도 사용가능하게 하기 위해
	// C++20 부터 template 람다 표현식 도입됩니다.
	auto swap2 = []<typename T>(T& a, T& b) { T tmp = std::move(a);
												a = std::move(b);
												b = std::move(tmp); };

	swap2(n, d); // error;
}