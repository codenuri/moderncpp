#include <iostream>
#include <type_traits> 

//#pragma pack(1)	// 구조체 align 을 1로 해달라는 것
struct PACKET
{
	char cmd;
	int  data;
};

// #pragma pack(1) : 대부분의 컴파일러가 지원하지만, 정확히는 C/C++ 표준이 아닙니다.

static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
			  "error, unexpected padding");
/*
int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/



template<typename T> void object_set_zero(T* p)
{
	memset(p, 0, sizeof(T)); 
}

class AAA
{
	int data;
};

int main()
{
	AAA aaa;
	object_set_zero(&aaa);
}