// 77 page
#include <iostream>

class Point
{
public:
	int x, y;
	Point(int a, int b) :x{ a }, y{ b } {  }
};

void draw_line(const Point& from, const Point& to) {}

void init(Point& pt) { pt.x = 0; pt.y = 0;}

int main()
{
	draw_line(Point{0, 0}, Point{5, 5});

    init(Point{1, 1}); // 되야 될까요 ? 안되야 될까요 ?

}





