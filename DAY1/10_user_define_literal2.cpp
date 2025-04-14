// 10_user_define_literal2.cpp

class Gram
{
	int value;
public:
	Gram(int v) : value(v) {}
};

Gram operator""gram(int n)
{
	Gram g(n);
	return g;
}

int main()
{
	// 사용자 정의 리터럴의 핵심원리
	// => 컴파일러가 약속된 함수를 찾는 것
	Gram g = 30gram; // operator""gram(30)
}