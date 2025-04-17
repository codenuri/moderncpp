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

}





