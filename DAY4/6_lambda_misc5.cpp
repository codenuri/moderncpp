#include <iostream>

class CompilerGeneratedName
{
	int v1;
public:
	inline int operator()(int a, int b) { return a + b + v1; }

	// 캡쳐한 람다는 아래 같은 함수를 만들수 없습니다.
	// => 멤버 데이타 접근하려면 멤버 함수만 가능
	// => 그래서 캡쳐한 람다는 함수포인터로 변환될수 없다는 규칙이 있습니다.
	static int helper(int a, int b)
	{
		return a + b + v1; // error
	}

	using PF = int(*)(int, int);

	operator PF() { return &CompilerGeneratedName::helper; }
};

int main()
{
	int v1 = 10;

//	int(*f1)(int, int) = [v1](int a, int b) {return a + b + v1; };

	int(*f1)(int, int) = CompilerGeneratedName{v1};

	std::cout << f1(1, 2) << std::endl;
}












