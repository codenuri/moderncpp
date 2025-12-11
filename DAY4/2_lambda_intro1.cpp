int add(int a, int b) { return a + b; }

void foo( int(*f)(int, int) )
{
	int ret = f(1, 2);
}

int main()
{
	// foo 함수는 인자로 함수(주소)를 요구
	foo(&add); // ok
	foo(add);  // ok

	// 람다 표현식
	// => 함수의 주소(이름) 이 필요한 위치에
	// => 함수 구현 자체를 표기하는 문법
	// => 이름이 없는 함수를 만든 다는 의미로 "익명의 함수" 라고도 합니다

	// [] : 람다가 시작됨을 알리는 기호
	//      lambda introducer 라고 합니다

	// 핵심 #1. 람다 표현식 만드는 법
	foo( [](int a, int b) { return a + b; } ); // ok
}