// 9_완벽한전달_주의사항3

// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 아래코드는 "forwarding reference" 일까요 ?
	// 아래코드는 "함수 템플릿일까요 ?" 일까요 ?
	// => 클래스 템플릿(Test)의 "일반(템플릿이 아닌) 멤버 함수"
	void foo(T&& arg) 	{}

	// forwarding reference 가 되려면 "함수 자체가 template" 이어야합니다.
	template<typename U>
	void goo(U&& arg) {}
};
int main()
{
	int n = 0;
	Test<int> t; // 이순간 T = int 로 결정.
				 // 따라서 foo(int&&) 로 생성.
	
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);	// error
	t.foo(10);	// ok 

	t.goo(n); // ok
	t.goo(10); // ok
}
