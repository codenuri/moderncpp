// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 아무 일도 하지 않은 디폴트 생성자가 필요하면

	// #1. 개발자가 직접 구현하는 방법
//	Point() {}

	// #2. 컴파일러에게 디폴트 생성자를 만들어 달라고 요청
	// => C++11 부터 제공 되는 아주 널리 사용되는 문법
	Point() = default;
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




