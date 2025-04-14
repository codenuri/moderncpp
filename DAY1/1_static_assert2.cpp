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
	// 가상함수가 있는 타입은 절대 memset 하면 안됩니다.
	// => 객체메모리 제일위에 있는 가상함수 테이블 포인터 까지 0으로 됩니다
	//	  
	// std::is_polymorphic<T>::value : T 타입에 가상함수가 있으면 true
	//								=> 목요일에 배우는 traits 기술

	static_assert(!std::is_polymorphic<T>::value,
				"error. T has virtual function");

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