#include <iostream>
#include <type_traits>
#include <concepts>

// std::is_integral_v<T> : T 가 정수인지 조사하는 traits
// std::integral<T>      : T 가 정수인지 조사하는 concept 이라는 새로운기술(C++20)

/*
template<typename T> requires std::integral<T>
void foo(T a)
{
}
*/
/*
// 위와 동일
template<std::integral T> 
void foo(T a)
{
}
*/

// 위와 동일
void foo(std::integral auto a)
{
}


int main()
{
	foo(3); // ok
	foo(3.4); // error. 조건 만족 못함
}