// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// #1. C++98 스타일의 반복자 얻기 
	// 단점 1. 코드가 복잡해 보인다
	// 단점 2. 유연성 부족. 컨테이너 변경시, 아래 코드도 수정되어야 합니다.
	std::vector<int>::iterator p1 = v.begin();
	std::vector<int>::iterator p2 = v.end();

	// #2. C++11 스타일, auto 사용
	// => 단, 아래 코드도 v 가 컨테이너가 아닌 raw array 라면???
	auto p3 = v.begin();
	auto p4 = v.end();

	// #3. C++11 에 추가된 또다른 개념. 
	// => 멤버 함신 대신 일반함수
	auto p5 = std::begin(v);
	auto p6 = std::end(v);
}