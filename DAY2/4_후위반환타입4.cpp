#include <iostream>
// ? 를 표기할수가 없었습니다.
// => 그래서 만든것이 decltype() 입니다.
/*
template<typename T1, typename T2>
? Mul(T1 a, T2 b)
{
	return a * b;
}
*/

// decltype(a * b) : a* b 를 했을때의 타입을 조사해 달라.
// => 그런데, 아래 코드는 에러 ?? 왜 에러일까요 ?
/*
template<typename T1, typename T2>
decltype(a * b) Mul(T1 a, T2 b) // a, b 를 선언전에 사용하고 있습니다.
{
	return a * b;
}
*/

// 후위 반환타입을 사용하면 됩니다.
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) ->decltype(a * b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;	

//  a = 30; // error. a 를 선언전에 사용
    int a = 10;
    a = 20; // ok
}

