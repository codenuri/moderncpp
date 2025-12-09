template<typename T> void f1(T a,  T b)  {}
template<typename T> void f2(T& a, T& b) {}

int main()
{
	int x[3] = { 1,2,3 };

	// 배열과 auto 추론
	// 아래 코드에서 a1, a2 의 타입은 ?
	auto  a1 = x;	// 1. int a1[3] = x; 로 결정했다면 error
					// 2. int* a1 = x;   로 결정했다면 ok.
					// => 그래서 우변이 배열이면 컴파일러는 좌변을 포인터로 추론

	auto& a2 = x;  // int (&a2)[3] = x; 로 결정해도 에러 아님.
				   // 따라서 이경우는
				   // auto : int[3]     a2 = int(&)[3];

	// 즉, 배열을 auto 변수에 담으면
	// auto  a1 = x; // 이때 auto 는 int*
	// auto& a2 = x; // 이때 auto 는 int[3],  a2 : int(&)[3]




	// 아래 코드에서 에러를 찾아 보세요
	f1("apple", "orange");
	f2("apple", "orange");
}
