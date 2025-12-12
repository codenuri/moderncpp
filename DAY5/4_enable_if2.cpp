#include <iostream>
#include <type_traits>

// gcd 는 정수 계열 타입만 사용가능하게 만들어 봅시다.

// #1. static_assert 
// => 조건을 만족하지 못하면 컴파일 에러!!
// => 조건을 만족하지 못하면 에러가 아닌 "후보에서 제외" 할수 없을까 ?
// => 다른 함수가 있다면 사용가능하도록!!

template<typename T> T gcd(T a, T b)
{
	static_assert( !std::is_integral_v<T>, "error, not integer");
	return 0;
}

double gcd(double, double)
{
	std::cout << "실수일때 다른 기술\n";
}

int main()
{
	gcd(6, 9);		// T 버전 사용
	gcd(3.1,  5.4);	// double 버전 사용
	gcd(3.1f, 5.4f);// T 사용. 그런데, float 이므로 실수 계열.. 
					// static_assert 실패 - 컴파일 에러
}
