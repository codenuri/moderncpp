#include <iostream>

// 90 page 
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


	int&& r2 = 10;
	foo(r2);	// int& 

	// int n = 0
	// Point pt{1,2};
	// 
	// 타입과 value category 를 잘 구별하세요

	//				타입				value category
	// n			int				lvalue		
	// 10			int				rvalue
	// pt			Point			lvalue	
	// Point{1,2}	Point			rvalue
	// r1			int&			lvalue
	// r2			int&&			lvalue ( r2라는 이름이 있다)

	// foo(int&)  : int& 타입을 받겠다는 것이 아니라 lvalue 를 받겠다
	// foo(int&&) : int&& 타입을 받겠다는 것이 아니라 rvalue 를 받겠다

	foo(r2); // int& 

	// r2를 foo(int&&) 에 보내려면 rvalue 로 캐스팅 필요
	foo(static_cast<int&&>(r2)); // int&&
	foo(std::move((r2));		 // int&&

	// 복습할때  구글에서 검색해 보세요
	// "named rvalue reference is lvalue"
}







