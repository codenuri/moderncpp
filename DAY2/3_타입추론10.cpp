int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	// auto 와 decltype 은 분명히 추론 규칙 다릅니다.
//	decltype(x[0]) d;	// int& d
	auto a = x[0];		// int a = x[0]


	auto ret1 = foo();	
//  int  ret1 = foo(); // auto 는 우변의 reference 를 제거하고 결정

	// decltype(함수호출식) : 함수의 선언을 보고 반환 타입조사
	decltype(foo()) ret2 = foo();
//  int&            ret2 = foo();

	// decltype(auto)
	// => C++14 부터
	// => decltype 규칙을 사용하는데 추론은 우변으로
	// => (auto) 위치에 우변을 넣으라는 의미
	decltype(auto) ret3 = foo(); 
//  decltype(foo()) ret3 = foo() 와 동일
}

