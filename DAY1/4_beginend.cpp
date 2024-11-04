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
	auto p3 = std::ranges::begin(v);
	auto p4 = std::ranges::end(v);
}
