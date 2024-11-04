// 7page
#include <cassert>

// assert : 실행시간 표현식의 유효성 조사
// static_assert : 컴파일시간 표현식의 유효성 조사


static_assert(sizeof(int*) >= 8, "error, not 64bit");


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
