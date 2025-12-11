#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// mutable 람다 표현식
	// => operator() 함수를 만들때 "const 함수로 하지 말라" 는 의미
	auto f1 = [v1, v2](int a) mutable { v1 = 200; return a + v1 + v2; };

	//--------------------------------------------------------
	/*
	class CompilerGeneratedName
	{
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1{ a }, v2{ b } {}

		inline auto operator()(int a) //const
		{
			v1 = 200;	// error
						// 단, mutable 람다라면 에러 아님.
			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName{v1, v2}; // main의 v1, v2
	*/
}





