#include <iostream>
// 템플릿사용시 추론된 타입을 확인하려면
// 방법 #1. godbolt.org 에서 어셈블리 코드 보세요 - 권장
// 방법 #2. 함수 이름(signature 포함)출력

template<typename T> void foo(T a)
{
	// __func__ : 함수 이름을 담은 매크로 (C++ 표준)
	std::cout << __func__ << std::endl;
}


int main()
{
	// #1. 타입을 명시적으로 전달하는 경우
	// => 사용자가 전달한 타입을 사용
	foo<int>(3.4);

	// #2. 타입을 명시적으로 전달하지 않은 경우
	// => 컴파일러가 인자로 보고 타입을 추론
	foo(10); // T : int
	foo(3.4);// T : double
}