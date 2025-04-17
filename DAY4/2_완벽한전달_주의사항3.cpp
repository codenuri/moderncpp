// 9_완벽한전달_주의사항3

// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 아래 함수의 인자는 "forwarding reference" 일까요 ?
	// => 아닙니다.
	// => forwarding reference 는 함수 템플릿 이어야 합니다.
	// => 아래 코드는 함수 템플릿 아닙니다
	void foo(T&& arg)
	{
	}

	// forwarding reference 가 되려면 함수 자체가 template 이어야합니다.
	template<typename U>
	void goo(U&& arg)
	{ }
};
int main()
{
	int n = 0;
	Test<int> t;	// 이순간 T 는 int 로 결정
					// => void foo(int&&) 로 결정됨
					// => 즉, foo 자체가 템플릿은 아닙니다.
	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);	// error
	t.foo(10);	// ok

	t.goo(n);	// ok
	t.goo(10);	// ok
}