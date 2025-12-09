// 타입추론7번 복사한후, 아래만 남기세요

template<typename T> void f1(T a,  T b)  {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	// 아래 ? 에 정확한 타입 표기해 보세요
	// "apple"  : const char[6]
	// "orange" : const char[7]

	// 아래 코드에서 에러를 찾아 보세요
	f1("apple", "orange");  // T 즉, 값으로 받고 있습니다.
		// const char[6] => const char* a로 전달
		// const char[7] => const char* b로 전달
		// 이므로 문제 없음.

	f2("apple", "orange"); // error
		// const char[6] => const char[6]의 reference 로 전달
		// const char[7] => const char[7]의 reference 로 전달




}
