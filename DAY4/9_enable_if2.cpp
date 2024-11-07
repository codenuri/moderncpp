#include <iostream>
#include <type_traits>


// 최대 공약수를 구하는 함수를 생각해 봅시다
// => 정수 계열 타입에만 사용되어야 합니다.
template<typename T> T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>, "error, T is not integer");
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
}
