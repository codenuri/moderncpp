#include <iostream>

// 람다 표현식 - 125page

int add(int a, int b) { return a + b; }

void foo( int(*f)(int, int) )
{
	int ret = f(1, 2);
}

int main()
{
	foo( &add ); // 이 코드가 정확한 표기법
	foo( add);   // 이 코드는 "함수이름은 함수 주소로 암시적 형변환 된다"
				 // 라는 문법을 활용한것

	// 람다 표현식(C++11)
	// => 함수 이름(주소)가 필요한 곳에, 함수 구현 자체를 보낼수 있는 표기법
	// => "익명의 함수" 라고 도 합니다.

	// [] : 람다가 시작됨을 알리는 기호
	//      lambda introducer 라고 합니다.

	foo( [](int a, int b) { return a + b; } );
}

// 람다표현식을 만드는 법을 먼저 알아 두세요
// => 함수 에서 "반환타입과 이름"을 제거하면 됩니다.