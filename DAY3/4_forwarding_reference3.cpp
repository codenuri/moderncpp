// 6_forwarding_reference1 - 아주 아주 중요!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 3;

f1(n); // ok
f1(3); // error

// 함수 인자로
// int&  : int 타입의 lvalue 만 전달할수 있다.
// int&& : int 타입의 rvalue 만 전달할수 있다.
// T&    : 임의(모든) 타입의 lvalue 만 전달할수 있다.

template<typename T> void f3(T& a)
{
}

int main()
{
	// 타입을 직접 전달하는 경우
	f3<int>(? );		// T = ?     T& = ?		f3(?)
	f3<int&>(? );
	f3<int&&>(? );
}



template<typename T> void f4(T&& a)
{
}
