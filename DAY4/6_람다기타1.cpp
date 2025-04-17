// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo() // void foo(Test* this)
	{
		// 멤버 데이타 캡쳐 ?
//		auto f = [](int a) { return a + data; }; // error

//		auto f = [data](int a) { return a + data; }; // error
										// data 는 지역변수 아님

		// 람다 표현식 안에서 멤버 데이타를 사용하려면 this 를 캡쳐하면됩니다.

//		auto f = [this](int a) { return a + data; }; // ok
										 // this->data 의 의미 입니다.

		auto f = [this](int a) { data = 10; }; // ok. 멤버 데이타 원본 수정
						// => data 를 캡쳐한것이 아니라
						// => 주소를 캡쳐 했으므로

	}
}

int main()
{
	Test t;
	t.foo();  // foo(&t)
}

