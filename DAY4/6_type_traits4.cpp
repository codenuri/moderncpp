// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

template<typename T> struct remove_pointer
{
	using type = T;
};

template<typename T> struct remove_pointer< T* >
{
	using type = T;
};

int main()
{
	remove_pointer<int*>::type n2; // int n2
}

template<typename T> void foo(T a)
{
	// 주의 : type 이 dependent name 이라면 typename 필요
	// => T에서 포인터 제거 타입

	typename remove_pointer<T>::type n1;

	// 아래 코드는 T에 관련 없음. typename 필요 없음
	remove_pointer<int*>::type n2;
}
