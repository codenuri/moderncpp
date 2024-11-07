#include <iostream>

// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()	// void foo(Test* this)
	{
		// 지역변수가 아닌 멤버 데이타 캡쳐 ?
//		auto f = [](int a) { return a + data; }; // error
//		auto f = [data](int a) { return a + data; }; // error. data 는 지역변수 아님

		// 멤버 데이타를 캡쳐하려면 "this" 를 캡쳐하면 됩니다.
		auto f = [this ](int a) { return a + data; }; // ok
								//		    this->data 의 의미.

		// 아래 코드는 결국 this 자체를 복사한것이므로
		// data 는 원본 객체의 수정하게 됩니다.
		auto f1 = [this](int a) { data = 10; };  //??
		f1(0);
		std::cout << data << std::endl;
	}
};

int main()
{
	Test t;
	t.foo(); // foo(&t)
}

