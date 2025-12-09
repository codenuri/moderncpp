// 초기화 용어 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n1{ 0 };	// direct initialization : = 없이 초기화 () 또는 {}
	int n2 = { 0 }; // copy   initialization : = 있는 초기화
	int n3;			// default initialization : primitive type지역변수는 쓰레기값, 
												// 사용자 정의 타입, 디폴트 생성자
	int n4{};		// value initialization
					// => 생성자 있다면 디폴트 생성자 호출 
					// => primitive type 이나 구조체는 0으로 초기화

	std::cout << n4 << std::endl; // 0

	// value 초기화는 일반적으로는 구조체 초기화할때 사용하는 것을 권장
	Point pt{}; // 1. Point 생성자가 있다면 호출
				// 2. 생성자가 없다면, 모든 멤버를 0으로 초기화

	std::cout << pt.x << std::endl;
}


