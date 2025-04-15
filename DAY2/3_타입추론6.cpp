// 20_타입추론5

template<typename T> void foo(T a) {}

int main()
{
	// #1. 템플릿은 호출시 전달한 인자로 타입 추론
	foo(10);		// 결국 이 코드는
//  T    a = 10;	// 이 코드 입니다.
	auto a = 10;	// 결국 auto 와 유사한 모양입니다.
					// 그래서 template 추론과 auto 추론은 거의 동일한 규칙사용

	//----------------------------------------------
	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto 추론은 템플릿 추론과 동일합니다.
	// 아래 각 변수의 타입을 생각해 보세요
	// T a1 = n 의 형식이므로 템플릿에서 배운 "규칙 #1"적용 하면 됩니다.
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

	// T& a5 = n; 이므로 템플릿에서 배운 "규칙 #2" 적용
	// => 우변의 reference 속성만 제거, const, volatile 은 유지
	auto& a5 = n;  // auto : int   a5 : int&
	auto& a6 = r;  // auto : int   a6 : int&
	auto& a7 = c;  // auto : const int   a7 : const int&
	auto& a8 = cr; // auto : const int   a8 : const int&

	// 결국 template 과 동일한 규칙 적용하면 됩니다.
	// template : T 타입을 조사하기 쉽다.
	// auto : auto 가 추론된 타입을 조사하기 어렵다.

	// 조사하고싶으면 "고의로 에러" 를 나오게 하세요
	// => 에러 메세지 않에 타입이 나타나게 됩니다.
	// => 정확하지 않을수도 있습니다.
	*a7 = 10;

	
}


