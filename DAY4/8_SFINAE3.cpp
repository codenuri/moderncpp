#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

template<typename T>
int foo(T a) 
{ 
	typename T::type n; // SFINAE 가 적용될까요 ?
					    // 에러가 나올까요 ?
						// => 에러
	return 0; 
}
// SFINAE 는 함수의 signature 가 실패 할때만 적용됩니다.
// => 반환 타입 위치
// => 함수 인자 위치
// => 템플릿 인자 위치

template<typename T>
typename T::type foo(T a) { return 0; }

template<typename T>
int foo(T a, typename T::type b = 0 ) { return 0; }

template<typename T, typename T2 = typename T::type >
int foo(T a ) { return 0; }

int main()
{
	foo(3); 
}
