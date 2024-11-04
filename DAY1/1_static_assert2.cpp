#include <iostream>
#include <type_traits> 

#pragma pack(1)	// 구조체 align 을 1단위로
struct PACKET	// padding 을 제거해 달라는 것
{
	char cmd;
	int  data;
};

static_assert (sizeof(PACKET) == sizeof(char) + sizeof(int),
			 "error, unexpected padding");

int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}






template<typename T> void object_set_zero(T* p)
{
	memset(p, 0, sizeof(T)); 
}
