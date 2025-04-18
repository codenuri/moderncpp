// 4_type_traits3 - 210 page
#include <iostream>

// 표준  traits 를 사용하려면 아래 헤더 필요 (C++11)
#include <type_traits>

// C++14 에서 아래 alias 를 제공합니다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T> void foo(T a)
{
	// 1. 조사하려면
	bool b1 = std::is_pointer<T>::value; // C++11 스타일
	bool b2 = std::is_pointer_v<T>;      // C++17 스타일


	// 2. 변형 타입을 얻으려면
	typename std::remove_pointer<T>::type n1; // C++11 스타일

	remove_pointer_t<T> n2; // 위와 동일
	std::remove_pointer_t<T> n3; // 이미 표준에 있습니다(C++14)


	
}

int main()
{
	int n = 0;
	foo(&n);
}
