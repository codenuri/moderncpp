#include <iostream>

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
auto Mul3(T1 a, T2 b) -> decltype(auto)
{
	return a * b;
}



int main()
{

}

