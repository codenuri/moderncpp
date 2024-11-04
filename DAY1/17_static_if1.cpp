// 51page.. if constexpr (static if)
// 
// 아래 코드가 왜 에러인지 생각해 보세요 ?
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10; // error. int 타입의 변수를 * 할수 없다.
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
	a.foo();	// 이렇게 사용해야지만 함수가 인스턴스화 된다.
				// 인스턴스화 : template => 실제 함수를 만드는 과정
}

// 지연된 인스턴스화 : 사용된 함수만 인스턴스화 된다는 개념