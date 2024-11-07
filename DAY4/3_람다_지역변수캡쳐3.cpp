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
	// => vector 는 같은 타입 여러개를 보관
	// => 모든 람다표현식은 다른 타입.
	// std::vector<auto> v1; // error

	// std::function<int(int, int)> 을 컨테이너에 담을수는 있습니다.
	std::vector< std::function<int(int, int)> > v;

	v.push_back([](int a, int b) { return a + b; });
	v.push_back([](int a, int b) { return a - b; });
	v.push_back([](int a, int b) { return a * b; });

	int n1 = v[0](1, 2);
	int n2 = v[1](1, 2);
	int n3 = v[2](1, 2);
}
