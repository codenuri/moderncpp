// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// #1. 람다표현식에서 전역변수 사용
	auto f1 = [](int a) { return a + g; }; // ok

	// #2. 람다표현식에서 지역변수 사용
	// => 캡쳐해야만 사용가능
//	auto f2 = [](int a) { return a + v1 + v2; }; // error
	auto f2 = [v1, v2](int a) { return a + v1 + v2; }; // ok

	// #3. 지역변수 수정(쓰기)
	// => "mutable lambda"로 해야 쓰기 가능
	// => "mutable lambda" : operator() 를 non-const 함수로 만들라는 의미
//	auto f3 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; // error
	auto f3 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; }; // ok

	f3(1); // v1 = 100 이 실행되지만
		   // 복사본이 변경된것

	std::cout << v1 << std::endl; // 10


	std::cout << sizeof(f3) << std::endl; // 8



	/*
	// 지역변수 캡쳐의 원리
	// => 컴파일러가 만든 클래스에 멤버 데이타가 추가된것
	// auto f3 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };

	class CompilerGeneratedName
	{
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int n1, int n2) : v1(n1), v2(n2) {}

//		inline auto operator()(int a) const
		inline auto operator()(int a)		// mutable lambda
		{
			v1 = 100;	// () 연산자가 상수함수라면 여기서 error
			return a + v1 + v2;
		}
	};
	auto f3 = CompilerGeneratedName(v1, v2); // 여기서 v1, v2는 
											 // main 의 지역변수
	*/
}





