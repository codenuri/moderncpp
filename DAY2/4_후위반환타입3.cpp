#include <iostream>

/*
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}

*/
// decltype : ? 같은 위치에 사용하려고 만든 코드
// 그런데 아래 코드가 에러 입니다.
template<typename T1, typename T2>
decltype(a * b) Mul(T1 a, T2 b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1) << std::endl;

	a = 10; // error. 변수를 선언 전에 사용
	int a = 0;
	a = 10; // ok
}

