#include <iostream>


template<typename T>
typename T::type foo(T a)  { std::cout << "T" << std::endl; return 0; }
//     int::type foo(int a) { ... }

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	foo(3); // 함수 호출시 어느 함수를 호출할지는 "인자"를 보고 결정
			// 따라서, 이코드는 T 버전을 사용하기로 결정하게 됩니다.
			// T = int 로 결정됩니다.
			// 그런데, 함수 모양이 "int::type foo(int a)" 가 되어서
			// 인스턴스화에 실패 했습니다.
			// => 에러는 아니고, 호출가능한 동일이름의 다른 함수가 있다면 사용.

	// Substitution Failure Is Not An Error
	// => SFINAE
}