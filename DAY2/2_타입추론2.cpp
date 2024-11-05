#include <iostream>
// 규칙 1. 인자가 값타입(T a) 일때
// => 함수 인자가 가진 "const, volatile, reference" 속성을 모두 제거후 타입결정
template<typename T> void foo(T a)
{
	// T 의 타입을 확인하는 방법 
	// #1. golbolt.org 에서 확인 => 가장 권장.. 
	// #2. 생성된 함수 이름 출력
	// __func__ : 함수이름을 가진 표준 매크로
	// __FUNCSIG__ : signature 를 포함한 함수이름 (VS 전용)
	// __PRETTY_FUNCTION__ : signature 를 포함한 함수이름 (G++ 전용)
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	// 사용자가 타입을 전달하면
	// => 무조건 사용자가 전달한 타입 사용
	foo<int>(3.4);

	// 사용자가 타입을 전달하지 않으면
	// => 함수 인자로 타입 결정
	foo(10); // T = int
	foo(3.4);// T = double

	//---------------------------------------------
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n);		// T = int
	foo(c);		// T = int
	foo(r);		// T = int
	foo(cr);	// T = int
}
