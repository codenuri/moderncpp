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

	// 규칙 #2. const lvalue reference 는 lvalue, rvalue 를 모두 가리킬수 있다
	const Point& r3 = pt;				// ok
	const Point& r4 = Point{ 0, 0 };	// ok
				// draw_line(Point{0,0}, Point{5,5}); 를 되게 하려고 만든문법
	
	// C++98 시절은 "위 2개의 규칙"
	// C++11 을 만들면서 아래 규칙 추가
	// => const 없이 rvalue 를 가리킬 필요가 생겼다(move, perfect forwarding)

	// 규칙 #3. rvalue reference 는 rvalue 만 가리킬수 있다.
	//		   (const, non-const 모두)
	Point&& r1 = pt;			// error
	Point&& r2 = Point{ 0, 0 };	// ok

}

// void draw_line(const Point& from, const Point& to) {}

/*
// 참고
// => 아래 코드를 많이 어려워 하십니다.
int&  r1 = 3;	// error
int&& r2 = 3;	// ok., 
				// 3이라는 "값"을 보관하기 위한 메모리 할당하고
				// r2 가 그 메모리를 가리키는 것
				// "temporary materialization(실체화)" 라고 부릅니다.
int n = 3;// 그냥 이렇게 하면 되는데 왜 ???
		  // => 당연히 "int&& r2 = 3" 를 직접 사용할 일은 없고
		  // => "모든 rvalue(주로 임시객체)에 적용하는 규칙을 만든것"

		  */








