#include <iostream>
#include <type_traits> 

// static_assert
// => 컴파일 시간에만 사용
// => 컴파일 후에는 제거됩니다.
// => 실행시간 오버헤드 전혀 없습니다.
// => 안전한 코드를 만드는 도구 입니다.
// => 되도록 많이 사용하세요

#pragma pack(1)	// 구조체 align 을 1단위로
struct PACKET	// padding 을 제거해 달라는 것
{
	char cmd;
	int  data;
};

static_assert (sizeof(PACKET) == sizeof(char) + sizeof(int),
			 "error, unexpected padding");

/*
int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/





template<typename T> void object_set_zero(T* p)
{
	// std::is_polymorphic_v<T> : T 가 가상함수가 있으면 true
	static_assert(!std::is_polymorphic_v<T>,
					"error. T has virtual function");

	memset(p, 0, sizeof(T)); 
}

class Data
{
	int data;

	virtual void foo() {}
};
int main()
{
	Data d;
	object_set_zero(&d);

}