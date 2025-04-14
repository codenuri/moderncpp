// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// STL 사용시 반복자를 꺼내는 방법

	// #1. C++98 스타일 
	// => 컨테이너 변경시 좌변의 타입이 수정되어야 합니다.
	// => 좋지 않습니다. 사용하지 마세요
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// #2. C++11 이후 권장 스타일
	// 1. auto 사용하세요
//	auto p1 = v.begin();
//	auto p2 = v.end();


	// 2. 멤버 함수 begin 대신 일반 함수 begin 사용
	// 장점 : v가 raw array 라도 사용 가능.
	auto p1 = std::begin(v);
	auto p2 = std::end(v);

}

// 아래 같은 코드에서 인자로 배열도 올수 있다고 생각할때 사용
template<typename T>
void use_container(T& c)
{
	auto p = c.begin(); // c가 배열이면 에러
	auto p = std::begin(c); // c가 배열이라도 ok
}