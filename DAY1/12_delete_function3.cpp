#include <iostream>

int gcd(int a, int b) 
{ 
	// a, b 의 최대 공약수 반환
	// => 세부 구현은 생략
	return a; 
}

int main()
{
	auto n1 = gcd(1, 2);
	auto n2 = gcd(1.1, 2.2);
}