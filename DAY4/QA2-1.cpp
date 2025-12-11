#include <functional>

void foo(int a, int b) {}

class Point
{
	int x, y;
public:
	void set(int a, int b) 
	{
		x = a;				
		y = b;				
	}
};
int main()
{
//	void(*f)(int, int) = &Point::set; // error

	// #1. 멤버함수의 주소를 담는 함수 포인터 만들기

	void(Point::*f)(int, int) = &Point::set; // ok

//	f(1, 2); // error. 객체가 없다. pt.set(1,2) 처럼 사용해야 한다.

	Point pt;
//	pt.f(1, 2); // error. f 는 멤버함수가 아니다.

	// 이때 사용하는 연산자가 .* 연산자(pointer to member 연산자)
//	pt.*f(1, 2); // error. 연산자 우선순위문제

	(pt.*f)(1, 2); // ok. 이 표기법이 멤버 함수 포인터로 멤버함수 호출
				   // 하기

	// 일반화 하기
	void(*f1)(int, int)        = &foo; // 일반함수 포인터
	void(Point::*f2)(int, int) = &Point::set; // 멤버 함수 포인터

	f1(1, 2);
//	f2(1, 2); // error
	(pt.*f2)(1, 2); // ok

	// 멤버 함수 포인터와 일반함수 포인터는 사용법이 다르다.
	// => 동일하게 사용하려면 
	std::invoke(f1, 1, 2);		// f1(1,2);
	std::invoke(f2, &pt, 1, 2); // (pt.*f2)(1,2)
}