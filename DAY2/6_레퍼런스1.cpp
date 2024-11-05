// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	Point pt(0, 0);

	// 규칙 #1. non-const lvalue reference 는 lvalue 만 가리킬수 있다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error


	// 규칙 #2. const lvalue reference 는 lvalue, rvalue를 모두 가리킬수 있다.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(0, 0);	// ok


	// 규칙 #3. rvalue reference 는 rvalue 만 가리킬수 있다.
	// => C++11 에서 추가됨
	// => 의도 : 상수성없이 임시객체를 가리키고 싶었다.
	// => move, perfect forwarding 을 위해 만든것
	Point&& r5 = pt;			// error
	Point&& r6 = Point(0, 0);	// ok

	// const rvalue reference 는 어떤가요 ?
	// => rvalue 만 가리킬수 있습니다.
	// => 그런데, 현재까지는 사용하는 경우가 없습니다.
	// => 그래서 대부분의 문서에서 다루지 않습니다.(이유는 move 배운후)
	const Point&& r7 = pt;			// error
	const Point&& r8 = Point(0, 0);	// ok
}
