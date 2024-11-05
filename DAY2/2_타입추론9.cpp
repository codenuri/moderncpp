#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4);
//  int  ret = foo(1, 3.4);로 결정. auto 는 우변의 reference 제거후 타입 결정


//  decltype(함수호출식) : 함수호출결과로 나오는 타입 조사
//						  함수의 반환 타입조사. 
//						  실제 함수가 호출되는 것은 아님. 선언문으로 조사
	decltype( foo(1, 3.4) ) ret2 = foo(1, 3.4);
//  int&                    ret2 = foo(1, 3.4);


	// C++14 : decltype(auto) 도입
	// => auto 자리에 우변을 넣어 달라.
	// => 또는, 우변으로 추론하는데, 규칙을 decltype 규칙으로
	decltype(auto) ret2 = foo(1, 3.4);
}
