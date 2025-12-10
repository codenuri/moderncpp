#include <iostream>

// 완벽한 전달 사전지식
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

	// 타입과 VALUE CATEGORY 를 잘 구별하세요
	// Point pt{1,1}
	
	//				타입				value category
	//	n			
	// 10
	// Point{1,1}
	// pt
	// r1
	// r2
}







