// 77 page
#include <iostream>

class Point
{
public:
	int x, y;
	Point(int a, int b) :x{ a }, y{ b } {  }
};

// 임시객체와 함수 인자 - 81 page

void draw_line(const Point& from, const Point& to) {}

int main()
{
	// (0, 0) ~ (5,5) 의 위치에 선을 그리고 싶다.
	// #1. 2개의 객체를 생성후에 전달
	Point from{ 0,0 };
	Point to{ 5,5 };

	draw_line(from, to);

	// #2. temporary(임시객체) 로 인자 전달.
	// => 위 코드보다 효율적이고 훨씬 널리 사용되는 코드
	draw_line(Point{0, 0}, Point{5, 5});

}





