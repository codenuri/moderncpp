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
	// 에러는 찾으세요
	auto f1  =   [](int a, int b) { return a + b; };
	auto& f2 =   [](int a, int b) { return a + b; };

	const auto& f3 = [](int a, int b) { return a + b; };

	auto&& f4 = [](int a, int b) { return a + b; };
}

