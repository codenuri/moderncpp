// 3_임시객체1 - 77 page
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
	Point pt(1, 2);
	
	// #1. 임시 객체는 등호의 왼쪽에 올수없다.(임시객체는 rvalue 이다.)
	pt.x = 10;				// ok
	Point(1, 2).x = 10;		// error.
						
	// #2. 임시 객체는 주소를 구할수 없다.
	// => 단, 생성자에서 "this" 사용은 가능
	Point* p1 = &pt;			// ok
	Point* p2 = &Point(1, 2);	// error
							
	// #3. 임시객체는 non-const 참조로 가리킬수 없다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error


	// #4. 임시객체를 const 참조로 가리킬수 있다. 핵심
	const Point& cr = Point(1, 2); // ok
}





