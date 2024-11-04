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
	int n1{ 0 };	// direct initialization ( = 이 없는 초기화 )
	int n2 = { 0 }; // copy   initialization

	int n3;			// default initialization
					// user type : 디폴트 생성자
					// int 같은 primitive : 쓰레기값

	int n4{};		// value initialization
					// 0 으로 초기화됨.
					// int 타입이면 {} 보다 {0} 권장

	std::cout << n4 << std::endl; // 0

	Point pt{};	// 1. 사용자가 만든생성자가 있다면 호출.
				// 2. 사용자가 만든생성자가 없거나, = defalut 로 된 생성자
				//    가 있다면 모든 멤버를 0 으로 

	std::cout << pt.x << std::endl;
}






