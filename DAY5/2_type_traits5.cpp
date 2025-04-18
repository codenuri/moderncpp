#include <iostream>
#include <type_traits>
// C++ 표준에 아래 traits 는 없습니다.
// => 재귀 학습용으로 만든 것
template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{

	using type = typename remove_all_pointer<T>::type;
};


int main()
{
	remove_all_pointer<int***>::type n;
}
