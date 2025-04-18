#include <iostream>
#include <type_traits>

template<typename T> struct is_array
{
	static constexpr bool value = false;
};

template<typename T> struct is_array< T[] >
{
	static constexpr bool value = true;
};


template<typename T> void foo(T& a)
{
	// is_array 만들어 보세요
	if ( is_array<T>::value ) 
		std::cout << "배열" << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}