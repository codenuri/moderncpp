// 10_user_define_literal2.cpp

class Gram
{
	int value;
public:
	Gram(int v) : value(v) {}
};

// 정수형 리터럴에 붙이는 접미사는 인자가 unsigned long long 이어야 합니다.
// => 34page 아래 표 참고
// => 또한 사용자가 만드는 리터럴은 반드시 _로 시작해야 합니다.
//    _가 붙지 않은 것은 표준에서 사용하기로 약속됨
// _가 없으면
// g++ : 컴파일 에러
// vs  : 경고 발생
//Gram operator""gram(unsigned long long n)
Gram operator""_gram(unsigned long long n)
{
	Gram g( static_cast<int>(n));
	return g;
}

int main()
{
	// 사용자 정의 리터럴의 핵심원리
	// => 컴파일러가 약속된 함수를 찾는 것
	Gram g = 30_gram; // operator""_gram(30)

	auto g2 = 30_gram;
}