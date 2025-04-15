// 핵심 : auto(template) 과 배열 이야기

template<typename T> void f1(T a,  T b)  {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	int x[3] = { 1,2,3 };

	// 아래 코드에서 auto 와 a1, a2 의 타입을 예측해 보세요

	auto  a1 = x;
			// 1. int a1[3] = x; 로 결정했다면 컴파일 에러
			// 2. int* a1 = x;   로 결정했다면 ok
			// 따라서 이경우
			// auto : int*    a1 : int*


	auto& a2 = x;			
			// int(&a2)[3] = x 로 결정해도 에러 아닙니다.
			// 따라서 이경우 auto 는
			// auto : int[3]	a2 : int(&)[3]  입니다.


	// 결론 auto 를  배열로 초기화 할때
	// 값 타입이면 : auto 는 포인터가 됩니다.
	// 참조 타입이면 : auto 는 배열 입니다, 






	// 다음중 에러는 ?
//	f1("apple", "orange");
//	f2("apple", "orange");
}