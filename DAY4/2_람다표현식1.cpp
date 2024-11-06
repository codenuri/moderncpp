#include <iostream>
#include <algorithm>
#include <functional> // 이안에 std::less<>, std::greater<> 같은 함수객체
					  // 이미 있습니다 - C++98
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// #1. 비교정책을 전달하지 않은 경우 => 오름 차순 정렬
	std::sort(v.begin(), v.end()); 

	// #2. 비교정책으로 일반 함수를 사용 => 비교정책이 인라인 치환 안됨
	std::sort(v.begin(), v.end(), cmp);

	// #3. 비교정책으로 함수객체를 사용 - 인라인 치환가능 
	std::less<int> f;

	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>{});


	// #4. C++11 부터 람다 표현식 사용가능

	// => 익명의 함수를 만드는 문법
	// => 함수, 함수 객체가 필요 한 위치에, 함수 구현 자체를 전달하는 문법
	// [] : lambda introducer
	//      람다표현식이 시작됨을 알리는 기호
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );
}





