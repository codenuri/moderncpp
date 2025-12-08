#include <iostream>

// C++11 부터 "리터럴 접미사"를 개발자가 만들수 있는 문법 도입

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};

// 정수형 리터럴 뒤에 붙이는 접미사는 반드시 unsigned long long 으로 해야 합니다.
// 단, 사용자가 만드는 리터럴 접미사는 _ 로 시작해야 한다. - 지키지 않으면 vc 는 경고, g++은 에러
// _로 시작하지 않은 것은 "표준 라이브러리"가 미래에 사용하기로 약속..
//Meter operator""m(unsigned long long n) // 경고 또는 에러
Meter operator""_m(unsigned long long n) // ok
{
	Meter meter( static_cast<int>(n) );
	return meter;
}  

int main()
{
	// 아래 코드를 생각해 보세요. 가독성이 좋지 않은가요 ?
	auto m = 3_m;	// 컴파일러는 이순간 약속된 함수를 찾게 됩니다
					// operator""m(3)

//	auto g = 3gram;
}