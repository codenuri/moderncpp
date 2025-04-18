#include <iostream>
#include <type_traits>

// type traits : 템플릿 인자 T의 다양한 특성(특질)을 조사하는 기술

// 만드는 법
// 1. 구조체 템플릿을 만들고 false 반환 ( value = false 로 하라는 의미)
// 2. 조건을 만족하는 부분 특수화 버전을 만들고 true 반환 ( value = true)

template<typename T> struct is_pointer
{
	static constexpr bool value = false;
};

template<typename T> struct is_pointer<T*>
{
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// 현재 T : int, int*

	if ( is_pointer<T>::value )

		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}