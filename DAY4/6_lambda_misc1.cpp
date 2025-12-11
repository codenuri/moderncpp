// 7_람다기타1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// 멤버 데이타 캡쳐 ?
		// auto f = [](int a) { return a + data; }; // error

		// auto f = [data](int a) { return a + data; }; // error. data 는 지역변수 아님

		auto f = [this](int a) { return a + data; };  // ok
						// 정확히는 data 가 아닌 자신의 주소를 캡쳐 한것
						// 따라서 "this->data" 로 사용해야 될것 같지만
						// "data" 로 사용. 

		// 정리
		// => 클래스 멤버 함수 안에서 람다 표현식 사용할때
		// => 멤버 데이타 접근하려면 this 캡쳐 사용. 
	}

};

int main()
{
	Test t;
	t.foo(); 
}

