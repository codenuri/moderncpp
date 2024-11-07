#include <iostream>
#include <type_traits>

// if constexpr 은 C++17 에서 표준에 추가
// => C++17 이전에는 enable_if 등의 기술로 해결

template<typename T> void printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> void printv(const T& v)
{
	std::cout << v << std::endl;
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}
