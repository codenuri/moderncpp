// 함수 인자와 레퍼런스

void f1(int&  r) {}
void f2(int&& r) {}

// 함수 인자로
// int&  : int 형 lvalue 만 받겠다는 의미.   "f1(3) 은 에러"
// int&& : int 형 rvalue 만 받겠다는 의미.   "f2(n) 은 에러"
// 
// T&    : 임의타입의 lvalue 만 받겠다는 의미.   "f3(3) 은 에러"



template<typename T> void f3(T& a)
{
}
int main()
{
	int n = 3;

	// #1. 타입인자를 명시적으로 전달하는 경우
	f3<int>(n);    // T = int     T& = int&			     f3(int& a)
	f3<int&>(n);   // T = int&    T& = int& &  => int&   f3(int& a)
	f3<int&&>(n);  // T = int&&   T& = int&& & => int&   f3(int& a)

	// #2. 타입인자를 생략하는 경우
	f3(3); // T 를 int, int&, int&& 중 어떠한것으로 해도 3을 받을수 없다.
		   // error	

	f3(n); // ok. n 은 int 이므로 T = int 로 결정
		   // f3(int&) 생성. 
}



template<typename T> void f4(T&& a)
{
}
