#include <iostream>
#include <type_traits>


// enable_if<true,  타입>::type => ? 
// enable_if<false, 타입>::type => ?


template<typename T> 

std::enable_if< std::is_integral_v<T, void>>::type 


gcd(T a, T b)
{
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
	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f);
}