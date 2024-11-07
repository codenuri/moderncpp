#include <iostream>

// auto 와 람다 표현식
int main()
{
	// 람다 표현식 활용
	// #1. std::sort(), std::find() 등의 알고리즘에 인자로 전달
	// #2. auto 변수에 담아서 함수 처럼 사용

	auto f1 = [](int a, int b) { return a + b; };
			// class xxx{ operator()(){...}}; xxx{};

//  auto f1 = 임시객체;
//	Point p = Point(0, 0); // 결국, Point p(0,0) 과 동일

	int n1 = f1(1, 2);
	int n2 = f1.operator()(1, 2);
	//------------------------------------
	// 다음중 에러를 모두 고르세요
	auto a1        = [](int a, int b) { return a + b; };
	auto& a2       = [](int a, int b) { return a + b; };
	const auto& a3 = [](int a, int b) { return a + b; };
	auto&& a4      = [](int a, int b) { return a + b; };
}

