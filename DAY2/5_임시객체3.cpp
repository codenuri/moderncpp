// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;
	Point(int a, int b) :x{ a }, y{ b } {  }
};

// 임시객체와 함수 인자 - 81 page

void draw_line(const Point& from, const Point& to) {}

void init(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	// (0, 0) ~ (5,5) 에 선을 그리고 싶다.

	// 방법 #1. 2개의 객체를 생성후 인자로 전달
	Point from{ 0, 0 };
	Point to{ 5, 5 };

	draw_line(from, to);
		// => 함수 호출이 종료되어도 from, to 는 파괴 되지 않습니다.
		// => 더이상 필요 없다면 즉시 파괴되는게 좋습니다.


	// 방법 #2. 인자를 임시객체로 전달
	draw_line( Point(0, 0), Point(5,5) );	 // 함수 호출 처럼 보일수 있습니다.	
	draw_line(Point{ 0, 0 }, Point{ 5, 5 }); // 이 코드가 좀더 명확합니다.
			// => 함수 호출이 종료되면 임시객체 는 즉시 파괴 됩니다.
			// => 인자 전달을 위한 객체는 "이름있는 객체" 보다
			//     임시객체(이름없는 객체)를사용하는 것이 좋습니다.


	// init 에 대해서 생각해 봅시다.
	Point pt{ 1,1 };
	init(pt);		// ok

	init( Point{ 1,1 } ); // 되는게 좋을까요 ? error 가 좋을까요 ?
						// 파괴될 객체를 변경하는 것은 아무의미 없습니다.
						// 현재 error 입니다.
	// 규칙
	// 임시객체는 "const reference" 로 받을수 있지만
	//           "non-const reference" 로는 받을수 없다.

	// 다음예제에서 자세히

	// 함수 인자가 const reference 
	// => 내부적으로 읽기만 하겠다는 의도
	// => 임시객체를 보낼수 있어야 한다.

	// 함수 인자가 non-const reference 
	// => 내부적으로 쓰기도 하겠다는 의도
	// => 임시객체를 보낼수 없어야 한다.

}





