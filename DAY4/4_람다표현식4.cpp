// 5_람다표현식5
#include <iostream>
#include <vector>
#include <algorithm>

// 람다표현식과 타입

int main()
{
	// #1. 모든 람다 표현식은 다른 타입 입니다.
	//     구현이 동일해도 모든 람다 표현식은 다른 타입입니다.

	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{};   xxx{};

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{};    yyy{};

	// #2. 아래 코드로 확인 가능합니다.
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;


	// #3. 람다표현식으로 초기화된 변수에 다른 람다 표현식
	//     담을수 없습니다.
	// => 이유는 타입이 다릅니다 (상수 라서가 아닙니다.)
	// 

	auto f3 = [](int a, int b) { return a + b; };

	f3 = [](int a, int b) { return a + b; }; // error
}





