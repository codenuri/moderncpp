template<typename T> void f1(T a, T b) {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	// 다음중 에러는 ?
	f1("apple", "orange");	// ok
	f2("apple", "orange");	// error

	// 타입의 정확히 알아야 합니다.
	// "apple"  : const char[6] 
	// "orange" : const char[7] 
	// => 크기가 다른 배열은 "다른타입" 입니다.

	// f2 : 인자로 reference 를 사용하므로 배열을 보내면 
	//	    배열로 전달 받게 됩니다.
	//      f2(T&, T&) 이므로 같은 타입을 전달해야 하는데, 
	//	    "apple", "orange" 는 다른 타입이므로 에러

	// f1 : 인자로 값타입을 사용하므로
	//	    배열을 보내면 포인터로 받게 됩니다.(decay 현상이라고 합니다.)
	// "apple"  : const char[6] 이지만 const char* 로 변환 가능
	// "orange" : const char[7] 이지만 const char* 로 변환 가능

	// 결국 같은 타입입니다. 에러 아님. 
}

// 핵심 
template<typename T> void f3(T) {}
template<typename T> void f4(T&) {}

f3(배열); // T = 포인터 입니다.
f4(배열); // T = 배열 입니다.




