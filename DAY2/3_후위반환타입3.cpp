#include <iostream>

// 아래 3개의 차이점을 생각해 봅시다.
// Mul1    : C++11 부터 가능
// Mul2, 3 : C++14 부터 가능

template<typename T1, typename T2>
auto Mul1(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

template<typename T1, typename T2>
auto Mul2(T1 a, T2 b) 
{
	return a * b;
}

template<typename T1, typename T2>
decltype(auto) Mul3(T1 a, T2 b)
{
	return a * b;
}
int main()
{


}

