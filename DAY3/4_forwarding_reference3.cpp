// 6_forwarding_reference1 - 아주 아주 중요!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 3;
f1(n); // ok
f1(3); // error. rvalue 를 보낼수 없다.

f2(n); // error
f2(3); // ok
//------------------------------------------------
// 함수 인자로
// int&  : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.

// T& : 임의 타입의 ? 

template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// #1. 사용자가 타입을 명시적으로 전달하는 경우
	f3<int>(? );	// T = ?      T& = ?     f3( ? a)
	f3<int&>(? );	// T = ?      T& = ?     f3( ? a)
	f3<int&&>(? );	// T = ?      T& = ?     f3( ? a)
}


