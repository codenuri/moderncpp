#include <iostream>

// 완성된 코드
// => 후위 반환 타입과 decltype 을 사용하는 코드!
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}


int main()
{
	std::cout << Mul(3, 4.1) << std::endl;

}

