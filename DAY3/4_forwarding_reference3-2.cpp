// 함수 인자로
// int&  : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.
// T&    : 임의 타입의 lvalue 만 받을수 있다. 

// T&&   : 임의 타입의 lvalue 와 rvalue 를 모두 받을수 있다.
//			=> 모두 받는 다는 것은 "해당 함수를 생성" 할수 있다는 의미
// 
// 인자로 lvalue(n) 를 보내면 : T = int&,  T&& = int&,   f4(int& ) 함수생성
// 인자로 rvalue(3) 를 보내면 : T = int ,  T&& = int&&,  f4(int&& )함수생성

// => 생성된 함수는 "call by value" 가 아닌 "call by reference"


// int&  : lvalue reference
// int&& : rvalue reference
// T&    : lvalue reference 
// T&&   : "rvalue reference" 아닙니다. lvalue, rvalue 모두 받을수 
//									   있습니다.

// C++11 초창기에 T&& 에 대한 이름이 없었습니다
// 그래서, "effective-modern c++" 책에서 아래 이름을 제안합니다.
// => "universal reference"

// 하지만, 이후 표준위원회에서는
// => "forwarding reference" 라는 이름을 사용하기로 결정. 
// => 이유는 주로 "perfect forwarding" 에 사용되기 때문에!!


template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 3;

	f4(n);	// T = int&,   T&& = int& &&     f4(int& a)
	f4(3);	// T = int     T&& = int&&       f4(int&&)
}

