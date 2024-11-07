#include <iostream>
#include <type_traits>
//                     
// enable_if< 조건, 타입 >::type
//			  true		   타입
//			  false       "::type" 없음

template<typename T> 
				// T 가 정수면				void
				//      정수아니면			::type 없음 - SFINAE에의해서 후보제외
typename std::enable_if< std::is_integral_v<T>, void >::type

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
