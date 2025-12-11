#include <iostream>

// auto 와 람다 표현식

int main()
{
	// 람다 표현식 활용 #1.
	// => find_if(), sort() 등에 인자로 사용 - 가장 널리 사용되는 기술

	// 활용 #2. auto 변수에 담아서 함수 처럼 사용
	// => main 함수 안에서 함수를 만든 것(C++은 함수안에서 함수 만들수없지만 람다는가능)
	// => main 의 지역변수도 사용가능(캡쳐하면)
	auto f1 = [](int a, int b) { return a + b; };
	// class xxx{ operator()() {} }; xxx{};

	int n1 = f1(1, 2);
	int n2 = f1.operator()(1, 2); // 람다 표현식은 결국 함수 객체이므로
									// 이렇게도 사용 가능.
	//------------------------------------------------
	// 다음중 에러는 모두 찾으세요.  => a2 만 에러.
	// 그리고 최선의 코드를 선택하세요
	// 

	auto a1		= [](int a, int b) { return a + b; };	 // Point a1 = Point{}; ok
	auto& a2	= [](int a, int b) { return a + b; };	 // Point& a2 =Point{}; error
	const auto& a3 = [](int a, int b) { return a + b; }; // const Point& a3 = Point{}; ok
	auto&& a4	= [](int a, int b) { return a + b; };	 // Point && a4 = Point{}; ok
														// => 아래 주석 참고

	
//	auto&& : rvalue reference 일까요 ? forwarding reference 일까요 ??
//			=> forwarding reference !! T&& 와 동일

//	auto&& b1 = n; // ok   int& b1 = n;
//	auto&& b2 = 3; // ok   int&& b2 = 3;


}

