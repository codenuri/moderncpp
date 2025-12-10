
// 함수 인자로
// int&  : int 타입의 lvalue 만 전달할수 있다.
// int&& : int 타입의 rvalue 만 전달할수 있다.
// T&    : 임의(모든) 타입의 lvalue 만 전달할수 있다.

// T&& : 
// => 새로운 추론 규칙
// 인자로 rvalue(3) 을 전달 : T = int,  T&& = int&&,   f4(int&&)
// 인자로 lvalue(n) 을 전달 : T = int&, T&& = int& &&, f4(int&)

// => 모든 타입의 lvalue, rvalue 를 모두 받을수 있는 함수
// => 정확히는 각각을 받을수 있는 "함수 생성"
// => 생성된 모든 함수는 "call by value" 가 아닌 "call by reference"
//    즉, 복사본 없이 원본 그대로, 모든 값을 받을수 있는 함수 템플릿


// 초기에 T&& 의 이름이 없었습니다.
// => 그래서 effective-C++ 책에서 "universal reference" 로 부르자고 제안
// => 그런데, 표준 위원회는 "forwarding reference" 로 부르기로 나중에 결정. 


template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 3;

	// 타입을 직접 전달하는 경우
	f4<int>(3);		// T = int    T&& = int&&		f4(int&&)
	f4<int&>(n);	// T = int&   T&& = int&  &&	f4(int&)
	f4<int&&>(3);	// T = int&&  T&& = int&& &&	f4(int&&)



	// 타입을 전달하지 않으면 컴파일러가 함수 인자로 타입 결정
	// => 최대한 함수를 생성하려고 노력합니다.
	f4(3); // T = int, T&& = int&&, f4(int&&) 되고, f4(3) 이므로 ok

	f4(n); // T = int,  T&& = int&&,   f4(int&&) 되고, f4(n) 이므로 error
		   // T = int&, T&& = int& &&, f4(int&)  이므로 ok
			// 즉, 템플릿 만들때 T&& 로 만들면 새로운 규칙 
			// 인자로 lvalue 보내면 T = & 타입으로 결정.

}








template<typename T> void f4(T&& a)
{
}
