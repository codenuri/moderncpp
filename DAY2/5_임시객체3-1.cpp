// 77 page
#include <iostream>

class Point
{
public:
	int x, y;
	Point(int a, int b) :x{ a }, y{ b } {  }
};

// 인자로 const &     사용 : 함수 안에서 인자를 읽기만 하겠다는 것
// 인자로 non-const & 사용 : 함수 안에서 인자를 R/W 모두 하겠다는 것
void draw_line(const Point& from, const Point& to) {}

void init(Point& pt) { pt.x = 0; pt.y = 0;}

int main()
{
	draw_line(Point{0, 0}, Point{5, 5}); // ok

    init(Point{1, 1}); // 되야 될까요 ? 안되야 될까요 ?
						// => 파괴될 객체를 수정하는 것은 논리적이지 않습니다.
						// => 그래서 error
						// => temporary 는 non-const& 로 받을수 없다.

	// 결국 temporary 관련 다양한 문법/특징이 있습니다.
	// => 다음 단계에서 정리

}





