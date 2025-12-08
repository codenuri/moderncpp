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
}
