// 73 page
#include <iostream>

template<typename T>
T Mul(T a, T b)
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4)   << std::endl;		// ok
	std::cout << Mul(3.1, 4.1)   << std::endl;	// ok

	std::cout << Mul(3, 4.1)   << std::endl;	// error.
								// 컴파일러가 타입 추론 못함
								// 1번째 인자로 결정하면 T = int
								// 2번째 인자로 결정하면 T = double
	std::cout << Mul<double>(3, 4.1)   << std::endl; // ok
}

