#include <iostream>
#include <concepts>

// 정수 계열 타입이 아닌 모든 타입 버전의 gcd는 삭제 해달라.
// => C++20 의 concept 기술 사용 ( 5일차 자세히 설명)
template<typename T> requires (!std::integral<T>)
T gcd(T a, T b) = delete; 

// 단, int 버전은 가능
int gcd(int a, int b)
{
	return 0;
}

int main()
{
	auto ret1 = gcd(10, 3);
//	auto ret2 = gcd(3.3, 3.2);
//	auto ret3 = gcd(3.3f, 3.2f);

	short s = 1;
	auto ret2 = gcd(s, s);
}

