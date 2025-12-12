#include <iostream>

// 표준  traits 를 사용하려면
// => C++11 부터 아래 헤더 제공
#include <type_traits>

// C++14 부터 아래 코드 제공
//template<typename T>
//using remove_pointer_t = typename std::remove_pointer<T>::type;

template<typename T> void foo(T a)
{
	// 1. 조사하려면
	bool b1 = std::is_pointer<T>::value; // C++11 스타일
	bool b2 = std::is_pointer_v<T>;	     // C++17 에서 추가, 위와동일한데
										 // 사용하기 쉽게 하기 위해


	// 2. 변형 타입을 얻으려면
	typename std::remove_pointer<T>::type n1;	// C++11

	std::remove_pointer_t<T> n2; // 위와 완전히 동일	// C++14
}



int main()
{
	int n = 0;
	foo(&n);
}
