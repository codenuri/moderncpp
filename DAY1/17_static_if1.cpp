// 아래 코드가 왜 에러인지 생각해 보세요 ?
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error. int 변수를 * 연산할수 없다.
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
		*data = 10; 
	}
};

int main()
{
	A<int> a;

	a.foo();
}

// 템플릿은 사용한 멤버 함수만 
// 실제 C++ class 에 포함됩니다.
// 위 코드에서 a.foo() 를 사용하지 않으면 위 코드는 에러 아닙니다.