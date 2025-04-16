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
	f4<int>(n);		// T =       T& = 			  f4(? a)
	f4<int&>(n);	// T =       T& = 			  f4(? a)
	f4<int&&>(n);	// T =       T& = 			  f4(? a)


}


