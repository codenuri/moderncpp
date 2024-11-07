#include <iostream>
#include <vector>
#include <functional>

int main()
{
	// 람다 표현식을 담는 3가지 방법
	auto f1            = [](int a, int b) { return a + b; };
	int(*f2)(int, int) = [](int a, int b) { return a + b; };

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	// 람다표현식 여러개를 vector 에 보관하고 싶다.
	std::vector<auto> v1; // ???
}
