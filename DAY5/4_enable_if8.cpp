#include <iostream>
#include <vector>
#include <type_traits>

template<typename T>
void foo(T a)
{
	// T�� ������ ���� �˰� �ʹ�.
	bool b1 = std::is_pointer_v<T>;

	// T�� STL �� �����̳����� �˰� �ʹ�.
	bool b2 = ? ;
}
int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);
}