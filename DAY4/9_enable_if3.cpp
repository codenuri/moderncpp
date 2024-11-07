#include <iostream>
#include <type_traits>
//                     
// enable_if< 조건, 타입 >::type
//			  true		   타입
//			  false       "::type" 없음

template<typename T> 
				// T 가 정수면				반환 타입은 T
				//      정수아니면			::type 없음 - SFINAE에의해서 후보제외
//typename std::enable_if< std::is_integral_v<T>, T >::type

std::enable_if_t< std::is_integral_v<T>, T >

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

// 결론
// => 템플릿을 조건을 만족할때만 사용하게 하려면

// 리턴 타입 자리를 아래 처럼 변경하세요
template<typename T> 
std::enable_if_t<조건, 반환 타입>
foo(T a)
{
}