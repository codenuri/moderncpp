//8_nullptr3
#include <iostream>

int main()
{
	// literal 과 타입
	// => 모든 값은 "타입"이 있다.
	3;			// int
	3.4;		// double
	"hello";	// const char[6]
	false;		// bool
	nullptr;	// std::nullptr_t 타입.
				// std::nullptr_t 타입은 모든 종류의 포인터로 암시적형변환 됩니다.
				
	std::nullptr_t a = nullptr;
//	std::nullptr_t b;	// 가능하지만 사용하지는 마세요

	int* p1 = a; // nullptr
//	double* p2 = b;

	void(*f)() = a;
}




