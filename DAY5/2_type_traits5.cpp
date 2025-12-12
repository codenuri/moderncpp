#include <iostream>
#include <type_traits>

template<typename T> struct remove_all_pointer
{
	using type = T;
};

template<typename T> struct remove_all_pointer<T*>
{
	using type = T;
};

int main()
{
	remove_all_pointer<int***>::type n;
}
