#include <iostream>

class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) { return a + b; }

	static int helper(int a, int b)
	{
		return a + b;
	}

	using PF = int(*)(int, int);

	operator PF() { return &CompilerGeneratedName::helper; }
};

int main()
{
	int v1 = 10;

//	int(*f1)(int, int) = [v1](int a, int b) {return a + b + v1; };

	int(*f1)(int, int) = CompilerGeneratedName{};

	std::cout << f1(1, 2) << std::endl;
}












