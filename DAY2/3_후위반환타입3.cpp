#include <iostream>

// 아래 3개의 차이점을 생각해 봅시다.
// Mul1    : C++11 부터 가능
// Mul2, 3 : C++14 부터 가능
// 사용자가 리턴 타입을 표기한것
// => 리턴 타입은 "decltype(a*b)" 의 결과
// => return 문장이 2개 이상이라도 ok.
template<typename T1, typename T2>
auto Mul1(T1 a, T2 b) -> decltype(a* b)
{
	if (a == 0) return 0;
	return a * b;
}

// 컴파일러에게 반환 타입을 추론해 달라는 것
// => return 문장을 보고 반환타입 추론
// => return 문장이 2개 이상이면 에러
// => 규칙은 auto 규칙
//    return "expression" 에서 expression 의 타입이 참조라도
//    반환타입은 값 타입
template<typename T1, typename T2>
auto Mul2(T1 a, T2 b) 
{
//	if (a == 0) return 0; // 이 코드가 있으면 에러
	return a * b;
}

// 위와 동일하지만 한개의 차이!!
// 추론 규칙이 auto 가 아닌 decltype
// => return "expression" 에서 expression 의 타입이 참조라면 참조반환
template<typename T1, typename T2>
decltype(auto) Mul3(T1 a, T2 b)
{
	return a * b;
}


int main()
{


}

