// 후위반환 - 73 page 아래 부분
#include <iostream>

// 아래 처럼 만들면
// => 1, 2인자가 같은 타입만 됩니다.
// => Mul(1, 3.4) 같은 코드가 에러 입니다.
template<typename T1>
T1 Mul(T1 a, T1 b)
{
	return a * b;
}
// 아래 처럼 만들면
// => 1, 2 인자를 다른 타입으로 할수 있습니다. - 좋은 함수 템플릿
// => 그런데 ? 가 문제 입니다. (해결은 다음 소스)
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

