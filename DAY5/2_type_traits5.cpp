#include <iostream>
#include <type_traits>
// C++ ǥ�ؿ� �Ʒ� traits �� �����ϴ�.
// => ��� �н������� ���� ��
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
