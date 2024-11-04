// 7page
#include <cassert>

// assert : 실행시간 표현식의 유효성 조사
// static_assert : 컴파일시간 표현식의 유효성 조사
// => 표현식이 반드시 컴파일 시간에 값을 알수 있어야 한다.
// => "constant expression" => 컴파일 할때 값을 알수 있는 표현식
// => 변수는 안됨.

static_assert( sizeof(int*) >= 8, "error, not 64bit" );
//static_assert( age > 0, ""); // error. 변수는 조사 안됨.

void foo(int age)
{
	// 함수 인자는 사용전에 유효성을 확인하는것이 좋습니다.
	assert(age > 0); // C 언어에서 부터 사용하던 기술

	int* p = new int[age];

	delete[] p;
}

int main()
{
	foo(-10);
}
