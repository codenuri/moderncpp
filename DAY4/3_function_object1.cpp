#include <iostream>
#include <algorithm>

// function object(함수 객체)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체
// => C++ 초창기(1980년대 부터 사용하던 개념)

// 일반 함수로 하면 되는데 ?? 왜 함수 객체를 사용하나요 ?
// 장점이 너무 많습니다
// 1. 상태를 가지는 함수
// 2. 인라인 치환성
// 3. 지역변수 캡쳐 등...

// C++20 부터는 표준라이브러리가 "일반 함수가 거의 없습니다."
// => 대부분 함수 객체.

struct Plus
{
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	Plus p;	// p 는 함수가 아닙니다. Plus 라는 구조체 타입의 객체(변수)	

	int n1 = p(1, 2); // 객체를 마치 함수 처럼 사용합니다. 함수객체라고합니다.	
	int n2 = p.operator()(1, 2); // 이렇게 컴파일 됩니다.
								// 사용자 직접 이렇게 호출해도 됩니다.
	

	// a + b;	// a.operator+(b)
	// a - b;	// a.operator-(b)
	// a();		// a.operator()()
	// a(1,2);	// a.operator()(1, 2)

	int n3 = std::max(1, 2); // C++98 표준 - 일반 함수(템플릿)
	int n4 = std::ranges::max(1, 2); // C++20 에서 새롭게 추가. 함수 객체
	int n5 = std::ranges::max.operator()(1, 2); // ok
}
