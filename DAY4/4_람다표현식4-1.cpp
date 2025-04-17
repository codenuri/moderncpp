#include <vector>
#include <functional> // std::less, std::greater

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 아래 코드의 단점 찾으세요
	// => 모든 람다 표현식은 다른 타입이므로
	// => 3개의 std::sort 생성
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 권장 : 동일한 람다 표현식을 여러번 사용할때는 auto 에 담아서 
	//        사용하는 것이 좋습니다.
	auto cmp = [](int a, int b) { return a < b; };

	// 아래 코드는 한개의 sort() 생성
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// 그런데!! < 비교가 필요 했다면 람다 표현식을 사용하지 말고
	// 이미 표준에 있는 less 를 사용하면 어떨까요 ?
	std::sort(v.begin(), v.end(), std::less{});
	std::sort(v.begin(), v.end(), std::less{});
	std::sort(v.begin(), v.end(), std::less{});

}