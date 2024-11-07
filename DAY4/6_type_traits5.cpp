#include <iostream>
#include <type_traits>

// 참고 
// remove_pointer => 표준에 있습니다.
// remove_all_pointer => 표준에는 없습니다.

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer< T* >
{				
	using type = typename remove_all_pointer<T>::type ;
};

int main()
{
	remove_all_pointer< int*** >::type n;
}
