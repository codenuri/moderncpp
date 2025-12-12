#include <iostream>
#include <type_traits>


// 선언문에서 이름을 제거하면 "타입"이 남게 됩니다.
int n;		// n의 타입 : int

double d;	// d의 타입 : double

int x[3];	// x의 타입 : int [3]
			//			  T[N]




template<typename T> struct is_array
{
	static constexpr bool value = false;

	static constexpr int size = -1;
};

// 핵심 
// 1. primary template 의 타입 인자가 한개라면 부분 특수화에서는 변경가능
// 2. template 인자는 타입 뿐 아니라 정수도 가능
// 단, primary template 이 타입인자가 한개 이므로
// => 오른쪽 끝의 부분특수화 표기에서는 인자가 한개 이어야 한다.
template<typename T, int N> struct is_array<T[N]>
{
	static constexpr bool value = true;
	static constexpr int size = N;
};




template<typename T> void foo(T& a)
{
	// T : int[3] 
	if ( is_array<T>::value ) 
		std::cout << "배열, 크기는 " << is_array<T>::size  << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()		// int() <= 함수 타입
{				// int(*)() <= 함수 포인터 타입
	int arr[3] = { 1,2,3 };
	foo(arr);
}
