// 

template<typename T> void foo(T a) {}

int main()
{
	// template 과 auto 
	foo(10);  // 인자로 T 타입 결정
//	T    a = 10; // 즉 이코드와 동일
	auto a = 10; // 결국 auto 와 유사. 그래서 auto 규칙도 template과동일

	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// 아래 코드에서 ? 의 타입을 생각해 보세요
	// T a1 = n  이므로 "규칙 #1" 적용
	//			 인자(우변)의 const, volatile, reference 모두 제거하고 결정
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

	// T& a5 = n   "규칙 #2" 적용 - 인자(우변)의 reference 속성만 제거
	auto& a5 = n;  // auto : int		 a5 : int&
	auto& a6 = r;  // auto : int		 a6 : int&
	auto& a7 = c;  // auto : const int   a7 : const int&	
	auto& a8 = cr; // auto : const int	 a8 : const int&
}


