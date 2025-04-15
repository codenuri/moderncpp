#include <iostream>

// 규칙 #1. 함수 템플릿의 인자가 값 타입 일때
// => 함수 호출식에 있는 인자의 "const, volatile, reference" 를 제거하고 
//    타입 결정
template<typename T> void foo(T a)
{
	std::cout << __FUNCSIG__ << std::endl;
	a = 100;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// 아래 코드의 경우 각각의 T 타입을 생각해 보세요
	foo(n);  // T = int
	foo(c);  // T = int
	foo(r);  // T = int
	foo(cr); // T = int
}