#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;


	// capture by value
//	auto f1 = [v1, v2](int a) mutable { v1 = 200; return a + v1 + v2; };

	// capture by reference
	auto f1 = [&v1, &v2](int a) { v1 = 200; return a + v1 + v2; };

	f1(5); 
	std::cout << v1 << std::endl; // 200

	//--------------------------------------------------------
	/*
	class CompilerGeneratedName
	{
		int& v1; // 컴파일러에 따라 int* 일수도 있습니다
		int& v2; // 표준 문서에 구현 방법을 강제하지는 않음
	public:
		CompilerGeneratedName(int& a, int& b) : v1{ a }, v2{ b } {}

		inline auto operator()(int a) const
		{	
			v1 = 200;	// v1 자체의 변경이 아닌 대상체 변경
						// *(v1.내부포인터) = 200

			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName{v1, v2}; // main의 v1, v2
	*/
}





