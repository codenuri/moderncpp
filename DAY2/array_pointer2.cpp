// array_pointer2.cpp
#include <stdio.h>

int main()
{
	int x[3] = {1,2,3};

	int* p1      = &x[0]; // 배열의 1번째 요소의 주소
	int (*p2)[3] = &x;    // 배열의 주소

	// p1, p2 는 현재 동일주소 입니다. 그런데, 타입이 다릅니다.
	// 포인터에 어떤 연산을 하면 "타입" 에 맞게 연산됩니다.
	printf("%p, %p\n", p1, p1 + 1); // ?
	printf("%p, %p\n", p2, p2 + 1); // ?
}