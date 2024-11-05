// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// 템플릿은 호출시 전달한 함수 인자로 타입 추론
	foo(10);
//	T    a = 10; // 결국 이 원리 인데, 
	auto a = 10; // auto 의 모양도 동일합니다.



	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 거의 유사 합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// T a1 = n; 의 모양이므로 규칙 #1 적용
	//				=> 우변의 const, volatile, reference 를 제거후 결정
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

	// T& a5 = n 의 모양이므로 규칙 2. 우변의 reference 만 제거후
	//								auto 결정
	auto& a5 = n;	// auto : int			a5 : int&
	auto& a6 = r;	// auto : int			a6 : int&
	auto& a7 = c;	// auto : const int		a7 : const int&
	auto& a8 = cr;	// auto : cosnt int		a8 : const int&
}


