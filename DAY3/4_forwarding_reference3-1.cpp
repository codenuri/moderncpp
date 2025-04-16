// 함수 인자로
// int&  : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.
// T&    : 임의 타입의 lvalue 만 받을수 있다. 
// T&&   :

template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 3;

	// #1. 사용자가 타입을 명시적으로 전달하는 경우
	f4<int>(3);		// T = int   T&& = int&&		     f4(int&& a)
	f4<int&>(n);	// T = int&  T&& = int& && => int&	 f4(int& a)
	f4<int&&>(3);	// T = int&& T&& = int&& && => int&& f4(int&& a)

	// 핵심은 아래!!
	// #2. 사용자가 타입을 전달하지 않을때
	f4(n);	// 1. int n 이므로 T = int 로 결정하면 최종 함수는 f4(int&& a)
			//    => rvalue 만 받을수 있으므로 컴파일 에러!
			// 2. T = int& 로 추론했다면 생성된 함수는 f4(int& )
			//     => f4(n) 을 사용할수 있다 => 컴파일 에러 아님..
			
			// 그래서 템플릿 인자가 T&& 일때는
			// lvalue 를 보내면 lvalue reference 로 타입 추론됨. 

	f4(3);	// T 를 int 또는 int&& 로 추론하면 f4(int&&) 가 생성되는데,
			// 표준에서는 T = int 로 추론.
			// 그래서 f4(int&&) 함수 생성
}

// 어제 추론
// 규칙 #1   foo(T a)
// 규칙 #2   foo(T& a)
// 규칙 #3   foo(T&& ) 일때 => 1, 2 와는 다른 규칙을 만들자는 것


