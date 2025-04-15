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
		// 임시객체를  const reference 로 가리키면 
		// 수명이 "cr" 의 수명으로 연장 됩니다
		// "lifetime extension" 이라는 개념..
	
		
//	cr.x = 10; // error. 단, cr은 상수 참조이므로  변경은 안됨


	// #5. C++11 만들때 상수가 아닌 참조로 임시객체를 가리키고 싶었습니다.
	// => move 와 perfect forwarding 기술을 위해서
	// => 그래서 새로운 참조 문법 등장
	// => rvalue reference 라는 C++11의 핵심 문법
	Point&& rr = Point{ 1,2 };
		
	rr.x = 10;	// ok..
				// 수명도 연장됨.
}





