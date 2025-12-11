#include <iostream>
#include <algorithm>

// lambda expression 장점 #1.

bool is_even(int n) { return n % 2 == 0; }

int main()
{
	int x[5] = { 2,4,6,3,8 };

	// 주어진 구간에서 처음 나오는 짝수를 찾고 싶다
	int* p1 = std::find_if(x, x + 5, is_even);

	// 주어진 구간에서 처음 나오는 k의 배수를 찾고 싶다 ??
	// => is_even 에서 main 함수의 지역변수 k 를 사용해야 한다.
	// => 그런데, 사용할수 없다. 
	// => 전역변수를 도입하는 방법밖에 없다.
	int k = 3;
	int* p2 = std::find_if(x, x + 5, is_even);


	// 람다 표현식의 장점 #1.
	// => 자신이 속한 문맥(main 함수) 의 지역변수에 접근할수 있다.
	// => 흔히 "지역변수를 캡쳐" 한다 라고 합니다.
	int* p3 = std::find_if(x, x + 5, [k](int n) { return n % k == 0; } );


}