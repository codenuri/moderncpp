#include <iostream>
#include <type_traits>

// enable_if<조건, 타입>::type
//          true          타입    "타입생략시는 void"
//          false         ::type 자체가 없음. 

// 결론
// => 반환 타입위치에 enable_if 를 사용하는 기술
// std::enable_if_t< 조건, "반환타입" > : 조건이 true 이면 반환 타입은 "반환타입"
//									 조건이 false 라면 반환 타입 만들수없음.
//									=> SFINAE 에 의해 에러 아님. 
//									=> 후보에서만 제외
// "반환타입" 생략시 void

// 결국 
// => 조건을 만족할때만 사용하는 템플릿 만드는 기술

template<typename T> 

//typename std::enable_if< std::is_integral_v<T>, T >::type // C++11 스타일

std::enable_if_t< std::is_integral_v<T>, T > // C++14 스타일
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
