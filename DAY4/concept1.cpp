#include <iostream>
#include <vector>
#include <type_traits>

// C++11 : move, perfect forwarding, lamba, variadic template....
// C++20 : concept, module, ranges, coroutine...

template<typename T>
void foo(const T& arg)
{
	bool b1 = std::is_pointer_v<T>;

	// T가 컨테이너인지 알고 싶다 ??
}
int main()
{
	std::vector<int> v = { 1,2,3 };
	foo(v);
}