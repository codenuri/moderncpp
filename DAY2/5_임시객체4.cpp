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
	Point pt{ 1, 2 };
	
	// #1. 임시객체는 등호의 왼쪽에 올수 없다.(rvalue 이다)
	pt.x = 10;				// ok. named object 는 lvalue 가 될수 있다.
	Point{ 1, 2 }.x = 10;	// error. 
						

	// #2. 임시객체는 주소 연산자로 주소를 구할수 없다.
	Point* p1 = &pt;			// ok
	Point* p2 = &Point{ 1, 2 };	// error
							

	// #3. 임시객체는 non-const reference 로 가리킬수 없다.
	Point& r1 = pt;				// ok
	Point& r2 = Point{ 1, 2 };	// error.


	// #4. 임시객체는 const reference 로 가리킬수 있다.
	const Point& cr = Point{ 1, 2 };	// ok
}





