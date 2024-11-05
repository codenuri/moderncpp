#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void init(Point& pt) { pt.x = 0; pt.y = 0; }

void draw_line(const Point& from, const Point& to) {}


int main()
{
	// (1,1) ~ (10,10) 의 선을 그리고 싶다.

	// #1. 객체를 생성해서 전달
	Point p1(1, 1);
	Point p2(10, 10);

	draw_line(p1, p2);




	std::cout << "-----" << std::endl;
}





