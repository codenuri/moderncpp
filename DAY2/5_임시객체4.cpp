// 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt{ 1, 2 };
	
	// #1. temporary 는 등호의 왼쪽에 올수 없다. lvalue 가 될수없다. rvalue 이다
	pt.x = 10;				// ok
	Point{ 1, 2 }.x = 10;	// error
						
	// #2. temporary 는 주소 연산자로 주소를 구할수 없다.
	Point* p1 = &pt;			// ok
	Point* p2 = &Point{ 1, 2 };	// error
							
	// #3. temporary 는 reference 로 가리킬수 없다.
	Point& r1 = pt;				// ok
	Point& r2 = Point{ 1, 2 };	// error

	// #4. temporary 는 const reference 로는 가리킬수 있다.
	const Point& r3 = Point{ 1, 2 };	// ok
}





