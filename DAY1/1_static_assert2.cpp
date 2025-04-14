#include <iostream>
#include <type_traits> 

#pragma pack(1)   // 구조체 멤버 align 을 1로 맞춰 달라
struct PACKET	  // padding 넣지 말라는 의미
{
	char cmd;
	int  data;
};

// PACKET 에 의도하지 않은 padding 이 놓이면 컴파일 멈추는 코드
static_assert (sizeof(PACKET) == sizeof(char) + sizeof(int),
				"error. unexpected padding!!!");

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

class Test
{
	int data;
public:
};

int main()
{
	Test t;
	object_set_zero(&t);
}