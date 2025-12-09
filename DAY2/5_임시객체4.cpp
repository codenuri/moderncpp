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
							
	// #3. temporary 는 non-reference 로 가리킬수 없다.
	Point& r1 = pt;				// ok
	Point& r2 = Point{ 1, 2 };	// error

	// #4. temporary 는 const reference 로는 가리킬수 있다.
	// => draw_line( Point{0, 0}, Point{5,5}) 가 되게 하려면 아래 문법 필요
	// => init( Point{0,0}) 이 안되게 하려면 #3 문법 필요

	const Point& r3 = Point{ 1, 2 };	// ok
					  // => 이순간 temporary 의 수명은 r3 의 수명으로 연장됩니다.
					  // => life-time extension 이라는 불리는 개념
					  // => Rust 등의 다른 언어도 가지고 있는 개념

	int x = r3.x; // ok
	r3.x = 10; // error. const.!!

	// 여기까지 설명은 C++98 시절 이야기 

	// #5. C++11 만들때 "temporary" 를 const 없이 참조로 가리킬 필요가 생겼다
	// => move 와 perfect forwarding 을 만들기 위해
	Point&& r4 = Point{1, 2}; // rvalue 만 가리키는 전용 reference
							  // 수명 연장됨
	Point&& r5 = pt; // error. Point&& 는 rvalue(temporary) 만 가리킬수 있다.
					// 이름있는 객체(lvalue) 는 가리킬수 없다.
	// 이제 용어가 아래 처럼 분류 됩니다.
	// Point&& : rvalue reference
	// Point&  : lvalue reference

}





