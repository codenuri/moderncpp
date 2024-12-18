﻿#include <iostream>

// 완벽한 전달0.cpp
// => 사전 지식

// 오버로딩 규칙 - 90p


void foo(int& a)  { std::cout << "1. int&" << std::endl; }
void foo(int&& a) { std::cout << "2. int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// 1. int&
	foo(10);	// 2. int&&

	int& r1 = n;
	foo(r1);	// 1. int& 


	int&& r2 = 10;
	foo(r2);	// 1. int&

	// expression(표현식) : 하나의 값을 만드는 코드 집합
	// expression이 만들어내는 값은 2개의 속성이 있습니다.
	// => data type, value category

	int n = 0;
	Point pt(1, 2);

	// expression	type		value category
	// 10			int			rvalue
	// n			int			lvalue
	// pt			Point		lvalue	
	// Point{0,0}	Point		rvalue
	// r1			int&		lvalue
	// r2			int&&		lvalue
	//-------------------------------------------------------
	// foo(int&)  : int&  타입을 받겠다는 것이 아니라 lvalue 를 받겠다는것
	// foo(int&&) : int&& 타입을 받겠다는 것이 아니라 rvalue 를 받겠다는것

	foo(r2); // foo(int&) 호출

	// r2 를 foo(int&&) 로 보내려면 "lvalue => rvalue" 로 캐스팅해야 합니다.
	
	foo( static_cast<int&&>(r2) ); // foo(int&&) 호출
			// => r2가 이미 int&& 타입인데, 같은 타입 캐스팅 아닌가요 ?
			// => 이 캐스팅은 타입 캐스팅이 아닌 "value 속성을 변경하는 캐스팅"
			// => cppreference.com 에서 static_cast 검색해보세요

	// 정리
	int&& r3 = 10;
	foo(r3);					// foo(int&),  r3는 lvalue
	foo(static_cast<int&&>(r3)); // foo(int&&), lvalue => rvalue 로 변경해서 호출
}







