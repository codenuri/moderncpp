#include <iostream>
#include <algorithm>
#include <vector>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3 };

	int k = 3;

	// 주어진 구간에서 k 의 배수를 찾고 싶다.
	auto p = std::find_if(v.begin(), v.end(), foo ); // k가 아닌 3의 배수


	// 람다표현식의 장점
	// => main 함수의 지역변수를 캡쳐해서 사용가능합니다.
	// => 그래서, 람다표현식이 만든 객체를 "클로져" 라고 합니다
	
	// 클로져(closure)
	// => 지역변수를 캡쳐하는 능력을 가진 함수(객체)

	auto p = std::find_if(v.begin(), v.end(), 				
					[k](int n) { return n % k == 0; });
}

// cppreference.com 
// => 1번째 화면 왼쪽에서 "expression" 선택후, lambda expression 찾아보세요