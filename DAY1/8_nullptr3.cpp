//8_nullptr3
#include <iostream>

int main()
{
	// 리터럴과 타입
	// => 모든 리터럴은 타입이 있습니다.
	3;		// int
	3.4;	// double
	3.4f;	// float

	"hello"; // const char[6]
	false;	 // bool

	nullptr; // std::nullptr_t 라는 타입이고
			 // std::nullptr_t 은 모든 포인터 타입으로 암시적 형변환 된다
			 // 라는 문법이 있습니다.

	std::nullptr_t a = nullptr;

	int* p1 = a;
	char* s1 = a;

	
}



