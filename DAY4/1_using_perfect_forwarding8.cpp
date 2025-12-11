// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 아래 foo 의 인자는 "forwarding reference" 일까요 ?
	// => forwarding reference 가 되려면 함수 자체가 template 이어야 합니다.
	// => 아래 함수는 함수 템플릿 아닙니다. 일반 멤버 함수 입니다.
	void foo(T&& arg)
	{
	}

	// 아래 코드가 "forwarding reference"
	template<typename U>
	void goo(U&& arg)
	{
	}
};
int main()
{
	int n = 0;
	Test<int> t;	// 이순간 T 타입은 이미 T = int 결정
					// foo(int&&) 로 이미 생성됨
	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);	// error
	t.foo(10);	// ok

	t.goo(n); // ok
	t.goo(10); // ok
}
// effective-c++, 
// more effective-c++,  
// effective-modern C++





