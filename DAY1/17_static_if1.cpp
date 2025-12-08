// 아래 코드에서 에러를 찾으세요
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error. int 변수인 data를 * 연산 할수 없다.
	}
};
int main()
{
	A a;
}
*/

template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10; // ?
	}
};

int main()
{
	A<int> a;

	// 이 코드는 왜 에러가 아닐까요 ?
	// => foo()를 사용한적이 없으므로, "template => 실제 클래스" 생성시 포함되지 않음
	// 아래처럼 사용하는 코드가 있다면 에러
	a.foo();
}
// 클래스 템플릿의 멤버 함수는 사용하는 경우만 실제 C++ 코드로 생성됨
// => 지연된 인스턴스화(lazy instantiation)