#include <iostream>
#include <type_traits>


// static_assert : 조건을 만족하지 않으면 에러!!

// 그런데, 조건을 만족하면 에러가 아니라..
// 후보에서 제외 될수 없을까 ?
// 즉, 동일이름의 다른 함수가 있다면 사용가능하도록 !!!

template<typename T> T gcd(T a, T b)
{
	static_assert (std::is_integral_v<T>, "error not integer");

	return 0;
}
double gcd(double, double)
{
	std::cout << "double\n";
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
	gcd(3.1f, 5.4f);
}