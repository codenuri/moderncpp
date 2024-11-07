#include <iostream>
#include <type_traits>

// is_pointer 복사해서 is_array 만들어 보세요

// 선언문에서 변수이름을 제거하면 타입만 남게 됩니다.

int n;		// n 의 타입은 int

double d;	// double 

int x[3];	// x의 타입은 int[3]  => 배열 타입
			//			  T[N] => 임의크기의 임의 타입 배열
			//			  T[]  => unknown size array type

template<typename T> struct is_array
{
	static constexpr bool value = false; 
	static constexpr int size = -1;
};

template<typename T, int N> struct is_array< T[N] >
{
	static constexpr bool value = true;
	static constexpr int size = N;
};

template<typename T> void foo(T& a)
{
	// T = int[3]
	if ( is_array<T>::value ) 
		std::cout << "배열 : " << is_array<T>::size  << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}
