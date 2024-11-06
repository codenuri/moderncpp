#include <iostream>

// 완벽한 전달 사전 지식
// 오버로딩 규칙 - 90p

void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// int&
	foo(10);	// int&&

	int& r1 = n;
	foo(r1);	// int&

	// 핵심은 아래 코드의 결과!

	int&& r2 = 10;
	foo(r2);	// 1
				// 10 은 rvalue 이지만 10을 가리키는
				// 레퍼런스 r2는 lvalue 이다.
				// 이름있고, 사용자가 만들고, 단일식을 벗어나 사용가능

	// 타입과 value 속성을 헷갈리지 마세요

	//				타입			value 속성
//	10				int			rvalue
//	n				int			lvalue
//	Point(1,2)		Point		rvalue
//	r1				int&		lvalue
//	r2				int&&		lvalue

//  foo(int&&) : int&& 타입을 받겠다는 것이 아니라
//				 rvalue 를 받겠다는 것. 

	foo(r2); // foo(int&) 호출
	foo(static_cast<int&&>(r2)); // foo(int&&) 호출

	// static_cast<int&&>(r2)
	// => r2가 이미 int&& 타입인데 ???  다시 int&& 타입으로 캐스팅 ??
}







