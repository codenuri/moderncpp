// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// 반복자는 꺼내는 방법
	// #1. C++98 시절
	// => 아래처럼 반복자 이름을 직접 사용하면
	// => 컨테이너 변경시 코드 수정됩니다. 사용하지 마세요
	// => auto 사용하세요
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// #2. C++11 auto
	// => 컨테이너를 변경해서 우변이 변경되지 않습니다.
	// => 아래 코드는 v 가 raw array 라면 에러!!
//	auto p1 = v.begin();
//	auto p2 = v.end();

	// #3. C++11, 멤버함수 begin 이 아닌 일반 함수 begin
	auto p1 = std::begin(v);
	auto p2 = std::end(v);    // v가 컨테이너 뿐 아니라 배열도 가능

	// #4. C++20 에서 새로운 begin 나왔습니다.
	// => visual studio 환경설정에서 C++20 으로
	// => "std::ranges" 라는 namespace 안에 있음.
	auto p3 = std::ranges::begin(v);
	auto p4 = std::ranges::end(v);


	// 왜??? 또 새로운것이 나와야 하나요 ??

//	auto p5 = std::begin( std::string("hello") );
						// 임시객체는 이문장의 끝에서 파괴 됩니다.
						// 따라서, 반환된 p5 는 절대 사용하면 안됩니다.

	auto p6 = std::ranges::begin(std::string("hello"));
						// 컴파일에러!!
						// 즉, 인자가 임시객체라면 에러발생
						// 이 외에도, 다양한 특징이 있습니다.

}

// visual studio 2022
// => 디폴트로 C++14 문법 사용
