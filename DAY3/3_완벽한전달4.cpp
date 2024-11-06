void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}
/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);	// 전혀 문제 없는 코드 입니다.
	f(static_cast<int&>(arg)); // 이 코드도 결국 위와 동일합니다.
								// 오버헤드도 없습니다.
								// 컴파일시 제거됩니다.(필요없는코드)
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/

// T&& 를 사용하면
// 1. 위 2개를 자동생성할수 있다.
// 2. int 뿐 아니라 모든 타입에 대해서도 가능. 

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 10;
	// 아래 코드 결과로 
	// 1. 생성된 함수 모양
	// 2. 캐스팅 코드 를 예측해 보세요
	chronometry(foo, 10);	// T = int     T&& = int&&
							// chronometry( 함수포인터, int&& arg )
							// => static_cast< int&& >(arg) 

	chronometry(goo, n);	// T = int&     T&& = int& && => int&
							// chronometry( 함수포인터, int& )
							// => static_cast<  int&  > (arg)
							// => 필요없는 캐스팅이지만 있어도 문제 없다

}





