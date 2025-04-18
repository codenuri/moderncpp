#include <iostream>
#include <type_traits>


// enable_if<true,  타입>::type => "타입" 
// enable_if<false, 타입>::type => ::type 없음

// enable_if<조건, void>::type
// 조건이 true 이면 : void
// 조건이 fasle라면 : ::type 없음


//std::enable_if< std::is_integral_v<T>, T>::type
// => T가 정수라면       : T
// => T가 정수가 아니면  : ::type 없음 => 함수 생성실패
//							SFINAE 에 따라 에러 아니고, 후보 제외

// 정리
// std::enable_if<조건, 반환타입>::type

// 조건을 만족하면 "반환타입"
// 조건을 만족하지 않으면 함수 생성실패, 에러 아니고, 사용하지 않겠다는것

template<typename T> 

//typename std::enable_if< std::is_integral_v<T>, T>::type

std::enable_if_t< std::is_integral_v<T>, T>


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