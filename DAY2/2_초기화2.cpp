#include <complex>

// 초기화 핵심 문법
int main()
{
	// C++98 스타일 : 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// C++11 uniform initialization 이라고 합니다.
	// => 모든 변수를 동일한 하나의 방법으로 초기화 할수 있다
	// => 흔히 "중괄호 초기화(brace-init)" 이라고 합니다.
	int n2 = { 10 };
	int x2[2] = { 1,2 };
	std::complex<double> c2 = { 1, 2 };

	// = 이 없어도 됩니다.
	int n3 { 10 };
	int x3[2] { 1,2 };
	std::complex<double> c3 { 1, 2 };

	// = 이 있는 초기화 : copy   initialization
	// = 이 없는 초기화 : direct initialization
	// => 약간의 차이가 있습니다. 이어지는 예제에서 설명
	// => 용어 외우세요
}












