#include <iostream>

// gcd(int) 버전에 있는데, gcd(실수)를 전달하면

// gcd(double) 버전이 없을때 : gcd(int) 버전 호출
//		=> 핵심 gcd(double)이 없지만 암시적 형반환에 의해 gcd(int) 호출

// gcd(double) 버전이 선언만 있을때 : "링크" 에러
//		=> 아래 소스가 실행파일이 아닌 동적모듈 처럼 빌드 되면
//		=> 링킹 하지 않으므로 "gcd(실수) 호출" 이 에러 아님.

//  gcd(double) 버전이 삭제 되었을때 : "컴파일" 에러
//--------------------------------------------------------

//double gcd(double a, double b); // 핵심 : 선언만!!

double gcd(double a, double b) = delete; // 일반 함수 도 삭제가능



int gcd(int a, int b)
{
	// a, b의 최대 공약수(gcd)반환 .. 구현 생략
	return 0;
}

int main()
{
	auto ret1 = gcd(10, 3);
	auto ret1 = gcd(3.3, 3.2);
}

