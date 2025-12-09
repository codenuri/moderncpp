#include <iostream>

// 추론된 타입 확인하는 방법.

template<typename T> void foo(T a)
{
	// T 의 타입을 확인하는 방법	
	// #1. 함수의 이름 출력
	// __func__ : 함수의 이름을 담은 C++ 표준 매크로(이름만 가진다)
	// __FUNCSIG__ : 함수이름 + 함수 인자 모양(모든 signature 출력)
	// std::cout << __func__ << std::endl;

	std::cout << __FUNCSIG__ << std::endl;

}
int main()
{
	// #1. 타입 인자를 명시적으로 전달하는 경우
	// => 무조건 사용자가 전달한 타입 사용
	// => 컴파일러가 타입 추론 안함
	foo<int>(3.4);

	// #2. 타입 인자를 전달하지 않는 경우.
	// => 컴파일러가 함수 인자를 보고 타입을 추론
	foo(10); // T = int 
	foo(3.4);// T = double
}
