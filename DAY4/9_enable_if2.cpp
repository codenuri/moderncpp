#include <iostream>
#include <type_traits>


// 최대 공약수를 구하는 함수를 생각해 봅시다
// => 정수 계열 타입에만 사용되어야 합니다.
template<typename T> T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>, "error, T is not integer");

	return 0;
}

double gcd(double, double)
{
	std::cout << "double\n";
	return 0;
}

int main()
{
	gcd(6, 9);			// T
	gcd(3.1,  5.4);		// double

	gcd(3.1f, 5.4f);	// T... 그런데, 정수가 아니므로 error
}

// static_assert : 조건을 만족하지 않으면 에러!!

// 조건을 만족하지 않을때, 에러가 아닌 후보에서 제외 할수 없을까 ?
// 그렇다면
// "gcd(3.1f, 5.4f)" 가 gcd(double)로 연결 될수 있다