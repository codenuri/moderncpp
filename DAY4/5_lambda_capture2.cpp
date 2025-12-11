#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	auto f1 = [v1, v2](int a) { return a + v1 + v2; }; 

	std::cout << sizeof(f1) << std::endl; // ??


	//--------------------------------------------------------
	// 지역변수 캡쳐의 원리
	// => 컴파일러가 아래 코드를 만드는 것
	/*
	class CompilerGeneratedName
	{
		// #1. 캡쳐한 람다 표현식은 "멤버 데이타"를 가진 클래스가 됩니다.
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1{ a }, v2{ b } {}

		inline auto operator()(int a) const
		{
			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName{v1, v2}; // main의 v1, v2
	*/
}





