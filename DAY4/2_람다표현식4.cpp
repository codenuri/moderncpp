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
	auto a1        = [](int a, int b) { return a + b; }; // ok 
	auto& a2       = [](int a, int b) { return a + b; }; // error
	const auto& a3 = [](int a, int b) { return a + b; }; // ok
	auto&& a4      = [](int a, int b) { return a + b; }; // ok
	
	// 참고 : auto&& 는 rvalue reference 아닙니다.
	//                  forwarding reference
	auto&& a5 = 10; // ok  // int&& a5 = 10
	auto&& a6 = n1; // ok  // int&  a6 = n1

	// 다음중 좋은 코드는 ?
	// => a1.  최적화에의해 임시객체 제거 되므로 오버헤드 없습니다.
	// => a3 는 결국 포인터, 사용시 주소를 따라가서 접근하므로 오버헤드 있습니다
	auto a1        = [](int a, int b) { return a + b; };  
	const auto& a3 = [](int a, int b) { return a + b; }; 
}

