#include <iostream>

int& foo(int& r) { return r; }

int main()
{
	int n = 3;

	// ret 의 타입은 ? 
	// => int
	// => auto 는 우변의 reference 를 제거하고 타입 결정
	auto ret = foo(n);


	// decltype(함수호출식) : 함수 호출결과로 나오는 타입 조사
	//						 결과적으로 함수 리턴 타입조사
	//						 함수가 실제 실행되는 것은 아님
	decltype(foo(n)) ret2 = foo(n);

	// 위 코드는 결국 "함수 호출표현식" 이 2번 표기 됩니다.
	// 아래 처럼 간단히 할수 있습니다.

	// auto 자리에 우변을 넣어달라
	// 또는, 우변으로 추론하는데, 규칙은 auto 가 아닌 decltype 으로!
	// => C++14 
	decltype(auto) ret3 = foo(n);
	ret3 = 300;
	std::cout << n << std::endl; // 300
}


 