#include <complex>

int main()
{
	// C++98 : 변수의 종류에 따라 초기화 방법이 다릅니다.
	int a1 = 10;
	int b1(10); 
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// C++11 "Uniform Initialization" 문법
	// => 모든 종류의 변수는 동일한 방법으로 초기화 가능하다.
	// => 흔히, 중괄호({}) 초기화(brace-init) 라고도 합니다.
	int a2{ 10 };
	int x2[2]{ 1,2 };
	std::complex<double> c2{ 1, 2 };

	// = 이 있어도 됩니다.
	int a3 = { 10 };
	int x3[2] = { 1,2 };
	std::complex<double> c3 = { 1, 2 };

	// direct initialization : = 이 없는 초기화
	// copy   initialization : = 이 있는 초기화
}












