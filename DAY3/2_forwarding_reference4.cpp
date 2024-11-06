// T&& 의 의미
// => 복습 하실때 아래 코드를 꼭 이해 하세요


// T&& : 임의 타입의 "lvalue, rvalue" 를 모두 받을수 있다.

// 모두 받는 다는 것은 "받을수 있는 함수를 생성" 할수 있다.
// => 즉, 한개의 함수가 아니라, 여러개 함수를 생성 한다.

// 인자로 int 타입의
// lvalue(n) 전달 : T=int&   T&&=int&   f4(int&) 
// rvalue(3) 전달 : T=int    T&&=int&&  f4(int&&)
// => 결국, 생성된 함수는 call by value 가 아닌 call by reference


// int&& : rvalue reference. "int"라고 타입이 결정된 것!!
// T&&   : ?			     템플릿 인자 "T" 사용


// T&& 이름
// effective c++ 책에서  "universal reference" 로 제안
// 하지만, 표준 위원회는 "forwarding reference" 라는 이름으로 결정
// => perfect forwarding 할때 사용하게 된다는 의미. 




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

void f1(T a) {}
void f2(T& a) {}
void f3(T&& a) {}

int n = 10;
f1(n); // T= int
f2(n); // T= int
f3(n); // T= int&   <== 이경우만 이렇게!!