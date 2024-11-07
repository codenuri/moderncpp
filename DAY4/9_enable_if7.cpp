#include <iostream>
#include <type_traits>

// C++11 enable_if 기술
/*
template<typename T>
std::enable_if_t< std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T>
std::enable_if_t< !std::is_pointer_v<T>>
printv(const T& v)
{
	std::cout << v << std::endl;
}
*/
// C++20 의 requires clauses 라는 문법.
// enable_if 라는 테크닉을 "문법으로 만든것!"
// => java, c# 의 generic constraint 기술과 유사.

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}
