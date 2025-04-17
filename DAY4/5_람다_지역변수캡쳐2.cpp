// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int main()
{
//	Point pt = Point{ 0, 0 } // => Point pt{0,0}

	int v1 = 10, v2 = 10;

	// 람다 표현식 : () 연산자가 상수 멤버 함수 입니다.
	// mutable 람다 표현식  : () 연산자가 상수 멤버 함수가 아닙니다.
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; 


	f1(0); // v1 = 100 실행됨. 하지만 람다표현식객체안의 복사본이 변경된것


	std::cout << v1 << std::endl; // 10


	std::cout << sizeof(f1) << std::endl; // ???



	/*
	// 지역변수 캡쳐의 원리
	class CompilerGeneratedName
	{
		// 지역변수를 캡쳐하면 멤버 데이타가 추가 됩니다.
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

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






