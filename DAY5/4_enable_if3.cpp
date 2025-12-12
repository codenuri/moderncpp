#include <iostream>
#include <type_traits>

// enable_if<조건, 타입>::type
//          true          ?
//          false         ?

template<typename T> 
std::enable_if_t< std::is_integral_v<T>, void >
gcd(T a, T b)
{
	return 0;
}

double gcd(double, double)
{
	std::cout << "실수일때 다른 기술\n";
}

int main()
{
	gcd(6, 9);		
	gcd(3.1, 5.4);	
	gcd(3.1f, 5.4f);
}
