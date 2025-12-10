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
	//	n			int				lvalue
	// 10			int				rvalue
	// Point{1,1}	Point			rvalue
	// pt			Point			lvalue
	// r1			int&			lvalue
	// r2			int&&			lvalue

	foo(r2); // int&
	foo(static_cast<int&&>(r2)); // int&&
				// r2 자체가 int&& 타입인데 ?? 다시 int&& 로 캐스팅하네요 ??
				// => 무슨 의미 인가요 ?
				// => <> 안에 && 가 있으면 타입 캐스팅이 아닙니다.
				// => value casting 입니다.
				// => lvalue => rvalue 로 바꾸는 캐스팅
}







