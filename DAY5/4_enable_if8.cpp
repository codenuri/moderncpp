#include <iostream>
#include <vector>
#include <type_traits>

template<typename T>
void foo(T a)
{
	// T가 포인터 인지 알고 싶다.
	bool b1 = std::is_pointer_v<T>;

	// T가 STL 의 컨테이너인지 알고 싶다.
	bool b2 = ? ;
}
int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);
}