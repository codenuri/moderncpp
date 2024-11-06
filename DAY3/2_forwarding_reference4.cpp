// T&& 의 의미
// => 복습 하실때 아래 코드를 꼭 이해 하세요

template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 3;

	// #1. 타입을 직접 전달하는 경우
	f4<int>(3);		// T = int		T&& = int&&				f4(int&& a)
	f4<int&>(n);	// T = int&		T&& = int& &&  => int&	f4(int& a)
	f4<int&&>(3);	// T = int&&	T&& = int&& && => int&&	f4(int&& a)


	// #2. 타입을 전달하지 않은 경우(핵심)
	// => 컴파일러는 함수인자를 보고 T를 결정해서 함수를 생성한다!!
	f4(n);	// n 은 int 타입
			// T = int  결정하면 "f4(int&& a)" 생성. f4(n) 은 에러
			// T = int& 결정하면 "f4(int& a)"  생성. f4(n) 은 에러 아님. 
			// => 그래서 C++ 에서는 이 경우만 T = int& 로 결정하기로 표준 정함

	f4(3);  // T = int 또는 int&& 하면 받을수 있는데, 
	        // 표준에서는 T=int 로 결정
			// 최종함수 는 f4(int&& a)
}