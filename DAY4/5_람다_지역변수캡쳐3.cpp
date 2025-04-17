// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;


//	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };

	auto f1 = [&v1, &v2](int a) mutable { v1 = 100; return a + v1 + v2; };

	f1(0);  // main 함수의 원본 v1 변경

	std::cout << v1 << std::endl; // 100





	/*
	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

//		inline auto operator()(int a) const
		inline auto operator()(int a)			// mutable 람다 표현식
		{
			v1 = 100;
			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName{ v1, v2 }; // main 지역변수를 생성자인자로전달

	*/


}






