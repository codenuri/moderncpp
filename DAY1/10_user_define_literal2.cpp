#include <iostrem>

// C++11 부터 "리터럴 접미사"를 개발자가 만들수 있는 문법 도입

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};

Meter operator""m(int n)
{
	Meter meter(n);
	return meter;
}

int main()
{
	// 아래 코드를 생각해 보세요. 가독성이 좋지 않은가요 ?
	auto m = 3m;	// 컴파일러는 이순간 약속된 함수를 찾게 됩니다
					// operator""m(3)

//	auto g = 3gram;
}