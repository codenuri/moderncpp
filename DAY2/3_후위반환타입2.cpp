// 후위반환 - 73 page 아래 부분
#include <iostream>

// #1. 아래 같은 코드의 ? 자리를 채우기 위해서 decltype 을 만든것
/*
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// #2. 그런데 아래 코드는 에러
// => a, b를 선언전에 사용하고 있는 코드
// => 이문제를 해결하기 위해 후위 반환 타입문법을 만든 것
/*
template<typename T1, typename T2>
decltype(a * b) Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// #3. 완성된 코드
template<typename T1, typename T2>
auto Mul(T1 a, T2 b)-> decltype(a* b)
{
	return a * b;
}
int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;

	a = 5; // error. a 를 선언 전에 사용
	int a = 0;
	a = 3; //ok
}

