// 10_user_define_literal2.cpp

class Gram
{
	int value;
public:
	Gram(int v) : value(v) {}
};

// 정수형 리터럴에 붙이는 접미사는 인자가 unsigned long long 이어야 합니다.
// => 34page 아래 표 참고
Gram operator""gram(unsigned long long n)
{
	Gram g( static_cast<int>(n));
	return g;
}

int main()
{
	// 사용자 정의 리터럴의 핵심원리
	// => 컴파일러가 약속된 함수를 찾는 것
	Gram g = 30gram; // operator""gram(30)
}