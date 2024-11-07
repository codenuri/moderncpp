#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입
// #1. 모든 람다 표현식은 "다른 타입" 입니다.
//     구현이 동일해도!!

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{}; xxx();

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{}; yyy();

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;


	// 이미 람다표현식으로 초기화된 변수에 다른 람다표현식담기
	// => error
	// => 타입이 다릅니다.
	// => 람다표현식으로 초기화된 변수에 다른 람다표현식 담을수 없습니다.
	f2 = [](int a, int b) { return a + b; };
}





