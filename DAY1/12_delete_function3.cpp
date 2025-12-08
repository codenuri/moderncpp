#include <iostream>
#include <concepts>

// 최대 공약수 개념은 "정수"만 가능한 개념입니다.
// 아래 코드에서 "gcd(double, double)" 버전이

// 1. 없다면 : 아래 main 의 "A" 는  에러 아님. double => int 의 암시적 형변환 발생
// 2. 구현이 있다면 : "A" 는 double 버전 호출
// 3. 선언만 있다면 : 컴파일 에러가 아닌 링크 에러. 의도적으로 사용하지 못하게 할때
//					사용했던 기술.
//					단점이 컴파일 에러가 아닌 링크 에러. 컴파일 단계에러 확인 안됨

// 4. 함수를 삭제하면 : "A" 부분은 무조건 컴파일 에러!

int gcd(int a, int b) 
{ 
	// a, b 의 최대 공약수 반환
	// => 세부 구현은 생략
	return a; 
}

//double gcd(double a, double b) { return a; } 
//double gcd(double a, double b);
//double gcd(double a, double b) = delete;
/*
template<typename T>
T gcd(T, T) = delete;   // int 버전외의 모든 버전은 삭제
*/

// 아래 코드는 정수 계열이 아닌 타입만 삭제. 
// => 단, requires 는 C++20 기술
template<typename T> requires (!std::integral<T>)
T gcd(T, T) = delete;   // int 버전외의 모든 버전은 삭제



int main()
{
	auto n1 = gcd(1, 2);
//	auto n2 = gcd(1.1, 2.2); // "A"
}