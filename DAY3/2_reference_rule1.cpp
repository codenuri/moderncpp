// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	Point pt{ 0, 0 };

	// 규칙 #1. non-const lvalue reference 는 lvalue 만 가리킬수 있다.
	Point& r1 = pt;				// ok
	Point& r2 = Point{ 0, 0 };	// error

	// 규칙 #2. const lvalue reference 는 lvalue 와 rvalue 를 모두 가리킨다
	const Point& r3 = pt;				// ok
	const Point& r4 = Point{ 0, 0 };	// ok


	// 규칙 #3. rvalue reference 는 rvalue 만 가리킬수 있다.
	// => C++11 만들때 rvalue(임시객체) 를 const 없이 가리킬 필요가
	//    있었습니다(move 와 perfect forwarding 을 만들기 위해)
	// => 그래서 새로운 reference 도입
	Point&& r3 = pt;			// error
	Point&& r4 = Point{ 0, 0 };	// ok

	// 그럼, "const rvalue reference 는 어떤까요 ??"
	// => rvalue 만 가리킵니다.
	// => 그런데, 현재 까지의 기술에서는 사용할 이유가 없습니다.
	//    move 를 알아야 이걸 이해할수 있습니다
}