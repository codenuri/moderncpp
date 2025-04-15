#include <iostream>

// #1. 리턴 타입을 생략한 코드 입니다.
// => "return 문장으로 반환타입을 추론해달라" 는 것
// => C++14 부터 지원
// 1. 2개 이상의 return 문이 있고 "서로 다른 타입"을 반환하면 error
// 2. "return exp" 에서 exp 가 참조 타입이어도 값으로 반환
//		(auto 추론이므로)
template<typename T1, typename T2>
auto Mul1(T1 a, T2 b)
{
	if (b == 1) return a;
	return a * b;
}
// Mul1(1, 3.4)



// #2. 아래 코드는 반환 타입을 표기한것
// => C++11 부터 사용가능
// => return 문장이 여러개 이고, 서로 다른 타입을 반환해도
// => return 타입은 "decltype(a*b)"
// => decltype(exp) 에서 exp 가 참조라면 반환 타입도 참조
//    auto 와 같이 참조 제거 현상 없음. 

template<typename T1, typename T2>
auto Mul2(T1 a, T2 b) -> decltype(a* b)
{
	if (b == 1) return a;  
	return a * b;
}

// #3. return 문장으로 추론해달라는것
// => 단, auto 방식이 아닌 decltype 방식
// => return 문장이 2개 이상 이고 서로 다른 타입으로 반환하면 error
// => C++14
template<typename T1, typename T2>
decltype(auto) Mul3(T1 a, T2 b) 
{
	return a * b;
}

// 결론
// 1. 리턴문장이 한개라면 : auto, decltype(auto) 도 좋은 코드
// 2. 리턴 문장이 여러개 이거나, 정확히 표현하려면
//    => Mul2 처럼 사용하는 것을 권장



int main()
{

}

