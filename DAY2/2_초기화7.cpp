
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// 핵심 : Point 클래스에 "디폴트 생성자가 없다" 는 점. 
// Point p1;		// error
// Point p2(0,0);	// ok

// 핵심 : 디폴트 생성자가 없는 Point 가 멤버 데이타로 있을때
class Rect
{
	Point pt1; 
	Point pt2;
public:
	// 아래 코드가 에러인 이유
	// 사용자 코드	// 컴파일러가 변경한 코드
	Rect() {}		// Rect() : pt1(), pt2() {}
};

int main()
{
	Rect r1;
}

