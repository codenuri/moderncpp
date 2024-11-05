// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	Point pt(0, 0);

	// 규칙 #1. non-const reference 는 lvalue 만 가리킬수 있다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error


	// 규칙 #2. const reference 는 lvalue, rvalue를 모두 가리킬수 있다.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(0, 0);	// ok


	// 규칙 #3. rvalue reference 는 rvalue 만 가리킬수 있다.
	// => C++11 에서 추가됨
	// => move, perfect forwarding 을 위해 만든것
	Point&& r5 = pt;			// error
	Point&& r6 = Point(0, 0);	// ok
}
