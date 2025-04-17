#include <iostream>

// auto 와 람다 표현식
int main()
{
	// 람다 표현식을 auto 변수에 담아서 함수 처럼 사용가능
	// ( 정확히는 람다표현식이 만든 임시객체를 f에 복사 해서 사용하는것)

	auto f = [](int a, int b) { return a + b; };	
			// class xxx{operator()(int a, int b){}}; xxx{};

	// 이제 f 는 일반 함수(인라인)처럼 사용하면 됩니다.
	int n = f(1, 2); 
	//------------------------------------------
	// 에러를 찾으세요
	auto f1  =   [](int a, int b) { return a + b; }; // ok

	auto& f2 =   [](int a, int b) { return a + b; }; // error
											// lvalue reference 로
											// rvalue 를 가리킬수 없다

	const auto& f3 = [](int a, int b) { return a + b; }; // ok

	auto&& f4 = [](int a, int b) { return a + b; }; // ok

	// T&&

	// auto && 은 T&& 입니다.(forwarding reference)
	// => 따라서 lvalue, rvalue 모두 가리킬수 있습니다.
	auto&& a1 = 10; // ok.  int&& a1 = 10
	auto&& a2 = n;  // ok.  int&  a2 = n;
}

