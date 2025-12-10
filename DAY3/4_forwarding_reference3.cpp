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
	int n = 3;

	// 타입을 직접 전달하는 경우
	f3<int>(n );		// T = int    T& = int&		f3(int&)
	f3<int&>(n );		// T = int&   T& = int& &	f3(int&)
	f3<int&&>(n );		// T = int&&  T& = int&& &	f3(int&)

	// 타입을 전달하지 않으면 컴파일러가 함수 인자로 타입 결정
	// => 최대한 함수를 생성하려고 노력합니다.
	f3(n); // T = int		T& = int&		f3(int&) ok.. 
	f3(3); // T = int		T& = int&		f3(int&) 인데 f3(3) 이므로 error
			// 혹시, T 를 int 가 아닌
			// int&, int&& 로 결정하면 받을수 있을까 ? 안된다..
}








template<typename T> void f4(T&& a)
{
}
