#include <iostream>


// SFINAE
// => "Substitution Failure Is Not An Error"
// => 치환에 실패한 것은 에러가 아니다.

// => 함수 템플릿을 사용하기로 결정하고, T 가 결정되고
//    함수 생성(인스턴스화)에서 실패 한것은 
//    에러는 아니고, 후보군에서 제외이다.

template<typename T>
typename T::type foo(T a) { std::cout << "T" << std::endl; return 0; }
//     int::type foo(int a) { .... }

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	foo(3); // 함수 찾을 때는 인자만 고려하게 됩니다.(리턴 타입이 아니라)
			// 함수 찾는 규칙에 따라서 foo(T) 를 선택하게 됩니다.
			// 그리고 T = int 로 결정후..
			// 함수를 생성합니다. => "int::type" 때문에 생성실패 합니다.
}
