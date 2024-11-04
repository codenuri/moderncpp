// 34 page
#include <iostream>

class Meter
{
	int value;
public:
	Meter(int v) : value(v) {}
};

// 사용자 정의 "정수형 리터럴" 함수의 인자는 unsigned long long 이어야 합니다.
Meter operator""m(unsigned long long value)
{
	Meter m(value);
	return m;
}


int main()
{
	Meter n = 3m; // operator""m(3) 를 찾게 됩니다.

//	Gram g = 300g;
//	auto g2 = 3kg;

	auto a1 = 3.4; // double
	auto a2 = 3.4f; // float
}




