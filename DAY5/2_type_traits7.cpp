#include <iostream>
#include <type_traits>


// 인스턴스화(instantiation)
// => 템플릿 => 실제 C++ 함수(클래스)를 만드는 과정

// if : 실행시간 조건문
// => 조건이 false 라면 인스턴스화에 포함된다.

// if constexpr : 컴파일시간 조건문
// => 조건이 false 라면 인스턴스화에 포함되지 않는다.

template<typename T> void printv(const T& v)
{
//	if ( std::is_pointer_v<T> )
	if constexpr (std::is_pointer_v<T>)

		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}


int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

