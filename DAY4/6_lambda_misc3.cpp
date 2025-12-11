int main()
{
	// generic lambda 를 사용한 swap 만들기
	auto swap = [](auto& a, auto& b) { int tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	// 아래 코드는 되는게 좋을까요 ? 안되는게 좋을까요 ?
	// => 안되야 합니다.
	swap(n, d); // 그런데, ok.
				// generic 람다표현식은 2개의 인자가 다른 템플릿 타입인자!

	// C++20 부터 "template lambda expression" 도입
	auto swap2 = []<typename T>(T& a, T& b) { int tmp = std::move(a);
										a = std::move(b);
										b = std::move(tmp); };

	swap2(n, d); // error
}
