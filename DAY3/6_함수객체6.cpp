#include <iostream>

// #1. 함수는 자신만의 타입이 없다.
//     signature(반환타입과 인자 모양)가 동일한 함수는 모두 같은 타입이다.

// #2. 함수객체는 자신만의 타입이 있다.
//     signature(반환타입과 인자 모양)가 동일해도 
//     모든 함수객체는 다른 타입이다.


struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(5, 3);
	Greater f2; f2(5, 3);
}