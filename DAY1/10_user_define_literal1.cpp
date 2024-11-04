// 34 page
#include <iostream>

class Meter
{
	int value;
public:
	Meter(int v) : value(v) {}
};

Meter operator""m(int value)
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




