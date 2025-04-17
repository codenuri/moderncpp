#include <iostream>

// function object(함수 객체) - 131 page
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

struct Plus
{
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

int main()
{
	Plus p;	// p 는 함수가 아닌 객체 입니다. Plus 라는 구조체 타입

	int n = p(1, 2);	// 객체 p를 함수 처럼 사용합니다.
						// "함수 객체" 라고 합니다.

	int n1 = p.operator()(1, 2); // 이렇게 멤버 함수이름을 직접 사용해도
								 // 됩니다.

	// 아래 코드에서 a 가 사용자 정의 타입의 객체라면
	// a + b	// a.operator+(b)
	// a - b	// a.operator-(b)
	// a()		// a.operator()()
	// a(1, 2)	// a.operator()(1,2)
}
