#include <iostream>
#include <algorithm>
#include <functional> 
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// 아래 코드에 대해서 생각해 보세요. 단점을 찾으세요
	// => sort() 함수가 3개 생성됩니다.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });


	// 핵심 : 람다표현식이 여러번 사용되는 경우 auto변수에 담아서 사용하세요
	// => 아래 코드는 sort 가 한개 생성

	auto cmp = [](int a, int b) { return a < b; }; // 타입결정

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// 만약 < 연산이 필요 했다면 
	// 람다 표현식대신 std::less 사용해도 됩니다.
	std::sort(v.begin(), v.end(), std::less<int>{});
	std::sort(v.begin(), v.end(), std::less<int>{});
	std::sort(v.begin(), v.end(), std::less<int>{});
}





