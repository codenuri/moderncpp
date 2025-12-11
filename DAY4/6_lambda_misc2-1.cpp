// C++14 부터 람다표현식 인자로 auto 사용가능합니다.

// 일반 함수 인자도 auto 될까요 ?
// => C++20 부터 됩니다.
// => 원리는 템플림
void foo(auto n)		// template<typename T> 
{						// void foo(T n)
}

auto add(auto a, auto b)  // template<typename T1, typename T2>
{						  // auto add(T1 a, T2 b)
	return a + b;
}

#include <concepts>
auto add2(std::integral auto a, std::integral  auto b)
{						  
	return a + b;
}

int main()
{
	foo(3);
	foo(3.4);

	auto n1 = add(1, 2);
	auto n2 = add(1.1, 2.2);
	auto n3 = add(1.1, 2);
	auto n4 = add2(1, 2); // ok
	auto n5 = add2(1.1, 2.2); // error
}

