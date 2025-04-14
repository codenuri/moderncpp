//8_nullptr3
#include <iostream>

int main()
{
	// literal 과 타입
	// => C/C++ 에서 모든 리터럴은 타입이 있습니다.
	3;			// int
	3.4;		// double
	"hello";	// const char[6]
	false;		// bool,     false 는 키워드 이고, 리터럴(값)입니다.
	nullptr;	// std::nullptr_t 타입,   키워드이고 리터럴 입니다.


	std::nullptr_t arg = nullptr;

	// std::nullptr_t 타입은 모든 종류의 포인터로 암시적 형변환 된다.
	// 라는 문법이 있습니다.

	int* p1 = arg;
	char* p2 = arg;

	// 참고 : C# 에는 null 이 있는데,,
	// => null 은 타입이 없다. 라고 정의되어 있습니다.
	// => 모든 값은 타입이 있지만 null 만 타입이 없다는 "일종의 예외"
}



