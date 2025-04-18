#include <iostream>
#include <type_traits>

// 변수 선언문에서 변수 이름을 제거 하면 "타입" 이 남게 됩니다.
/*
int    n;	// 변수이름 : n		타입 : int
double d;	// 변수이름 : d      타입 : double
void foo(int); // 함수이름 : foo	  타입 :void(int)
int x[3];	// 변수 이름 : x		타입 : int[3]
		
int[3]; // int     3개 크기 배열
T[3];   // 임의타입 3개 크기 배열
T[N];   // 임의타입 모든 크기 배열

//T[];// 크기를 알수 없는 배열(unknown size array) 
	  // C에서 특별한 경우 함수인자등에서 사용 ( C 매뉴얼 참고)
*/



template<typename T> struct is_array
{
	static constexpr bool value = false;
	static constexpr int size = -1;
};

template<typename T, int N> struct is_array< T[N] >
{
	static constexpr bool value = true;
	static constexpr int size = N ;
};

// 크기가 없는 배열도 배열이므로 아래와 같이 별도로 추가
template<typename T, int N> struct is_array< T[] >
{
	static constexpr bool value = true;
};


template<typename T> void foo(T& a)
{
	// T : int[3]
	if ( is_array<T>::value ) 
		std::cout << "배열, 크기는 " << is_array<T>::size  << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}