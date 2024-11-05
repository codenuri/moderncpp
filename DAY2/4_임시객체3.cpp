#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
// 핵심 : 임시객체는 non-const reference 로는 받을수 없다.
//       임시객체2.cpp 참고
void init(Point& pt) { pt.x = 0; pt.y = 0; }

void draw_line(const Point& from, const Point& to) {}


int main()
{
	// (1,1) ~ (10,10) 의 선을 그리고 싶다.

	// #1. 객체를 생성해서 전달
	Point p1(1, 1);
	Point p2(10, 10);

	draw_line(p1, p2);


	// #2. 임시 객체 형태로 전달
	draw_line(Point(1, 1), Point(10, 10)); 
				// => 함수 호출이 종료되면 즉시 파괴

	// #3. init : x, y 를 0으로 리셋하는 함수
	init(&p1); // ok

	init( Point(1, 1) ); // error. 


	std::cout << "-----" << std::endl;
}





