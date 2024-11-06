// 함수 인자와 레퍼런스

void f1(int&  r) {}
void f2(int&& r) {}

// 함수 인자로
// int&  : int 형 lvalue 만 받겠다는 의미.   "f1(3) 은 에러"
// int&& : int 형 rvalue 만 받겠다는 의미.   "f2(n) 은 에러"
// 
// T&    : 



template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// #1. 타입인자를 명시적으로 전달하는 경우
	f3<int>(? );   // T = ?     T& = ?    f3(? a)
	f3<int&>(? );  // T = ?     T& = ?    f3(? a)
	f3<int&&>(? ); // T = ?     T& = ?    f3(? a)

	// #2. 타입인자를 생략하는 경우
	f3(3);
	f3(n);
}



template<typename T> void f4(T&& a)
{
}
