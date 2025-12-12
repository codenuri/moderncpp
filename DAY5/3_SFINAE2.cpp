#include <iostream>

// SFINAE
// => Substitution Failure Is Not An Error   의 약자
// => 치환 실패는 에러가 아니다.

// 함수 템플릿을 사용하기로 결정했는데
// => T 의 타입을 결정하고, 함수 를 생성할때
// => 리턴 타입, 함수 인자의 모양에서 오류가 발생하면
// => 에러는 아니고, 함수를 생성못했으므로 후보에서 제외된다.
// => 동일이름의 다른 함수가 있다면 사용가능하다.


template<typename T>
typename T::type foo(T a)  { std::cout << "T" << std::endl; return 0; }
//     int::type foo(int a) { ... } 로 함수 생성

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	foo(3); // foo(T) 가 우선적으로 호출
}
