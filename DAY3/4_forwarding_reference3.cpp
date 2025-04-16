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

// T& : 임의 타입의 lvalue 만 받을수 있다. 

template<typename T> void f3(T& a)
{
}
int main()
{
	int n = 3;

	// #1. 사용자가 타입을 명시적으로 전달하는 경우
	f3<int>(n);		// T = int      T& = int&			  f3(int& a)
	f3<int&>(n);	// T = int&     T& = int& &  => int&  f3(int& a)
	f3<int&&>(n);	// T = int&&    T& = int&& & => int&  f3(int& a)

	// #2. 사용자가 타입을 전달하지 않으면
	// => 컴파일러가 함수 인자를 보고 함수를 T의 타입을 결정해서
	//    함수를 생성
	f3(n);	// T = int, 인자는 T& = int&   생성된 함수 f3(int&)
			// ok. 아무 문제 없다.
	f3(3);	// T = int로 결정하면 f3(int&) 생성되는데 3 을 받을수 없다.error
			// T = int&, int&& 중 어떠한 것으로 결정해서 받을수 없다.
			// 항상 컴파일 에러!
}


