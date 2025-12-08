#include <iostream>

// static_assert : 7 page

// static_assert(조건, 메세지)
// => 조건을 만족하지 않으면 컴파일을 멈추고, 메세지를 출력해 달라

static_assert(sizeof(int*) == 8, "error not 64bit");

int main()
{
	// 64bit 환경에서만 동작가능한 코드
}