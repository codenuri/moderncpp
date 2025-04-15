// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {}
	Point() = default;
};

int main()
{
	int n1{ 0 };	// direct intialization
	int n2 = { 0 };	// copy initialization

	int n3;			// default initilization 
					// => 지역변수 : 쓰레기값, 전역변수 : 0

	int n4{};		// value initialization
					// => primitive 타입 : 0
					// => user define 타입 : 디폴트 생성자 호출

	std::cout << n4 << std::endl; // 0

	Point pt{};		// Point 에 생성자가 없거나
					// "=default" 로만든 생성자가 있다면
					// => 모든 멤버 가 0으로 초기화
					
					// 사용자가 만든 생성자가 있다면
					// => 생성자만 호출, 0으로 초기화 안됨.

	std::cout << pt.x << std::endl;
}


