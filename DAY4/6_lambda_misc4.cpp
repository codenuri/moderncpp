#include <iostream>


// 람다 표현식 사용시 컴파일러가 만드는 클래스라고 가정
class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) { return a + b; }

	// 함수 포인터로의 변환을 위해서는 operator()와 동일한 기능의 
	// 멤버함수가 아닌 함수도 필요
	// 1. static 멤버 함수로 만들거나
	// 2. 일반 함수등으로 만들거나
	// 3. 또다른 기술 필요
	// => static 멤버가 제일 편함.
	static int helper(int a, int b)
	{
		return a + b;
	}


	using PF = int(*)(int, int);

//	operator PF() { return &CompilerGeneratedName::operator(); }
						// => error. operator() 함수는 멤버 함수이다.
						// => this가 추가되는 함수 인데, PF 는 일반함수포인터.

	operator PF() { return &CompilerGeneratedName::helper; }
};

int main()
{
	int(*f1)(int, int) = CompilerGeneratedName{};
						// 임시객체.operator 함수포인터타입()

	std::cout << f1(1, 2) << std::endl;


//	int(*f1)(int, int) = [](int a, int b) {return a + b; };
						// class xxx{}; xxx{};
}












