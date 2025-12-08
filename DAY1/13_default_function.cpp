// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
//	Point() {}  // 사용자가 만드는 디폴트 생성자
				// 그런데, 아무 일도 하지 않은 디폴트 생성자가 필요하면
				// 이렇게 하는 것은 좋지 않은 코드

	Point() = default; // 좋은 코드
						// 컴파일러에게 디폴트 생성자를 만들어 달라고 요청

	Point(int a, int b) {} // 
};

int main()
{
	Point p1;
	Point p2(1, 2); // 인자가 2개인 생성자 호출
}




