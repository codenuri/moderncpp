// 34 page
#include <iostream>

class Meter
{
	int value;
public:
	Meter(int v) : value(v) {}
};


// 사용자 정의 "정수형 리터럴" 함수의 인자는 unsigned long long 이어야 합니다.
// 또한, 일반 사용자가 만드는 것은 반드시 _ 로 시작해야 합니다.
// _가 없는 것은 C++표준에서 사용
Meter operator""_m(unsigned long long value)
{
	Meter m(static_cast<int>(value));
	return m;
}


int main()
{
	Meter n = 3_m; // operator""m(3) 를 찾게 됩니다.

//	Gram g = 300g;
//	auto g2 = 3kg;

	auto a1 = 3.4; // double
	auto a2 = 3.4f; // float
}




