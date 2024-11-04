
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

class Rect
{
	Point pt; 
public:
	// 사용자가만든 생성자		// 컴파일러가 변경한 생성자
//	Rect() {}					// Rect() : pt() {} 
								// => Point 에 디폴트 생성자가 없으므로 error

	// 핵심 : 디폴트 생성자가 없는 멤버 데이타가 있다면
	//		반드시 사용자가 다른 생성자를 호출하는 코드를 제공해야 합니다.
	//      => C++98
	Rect() : pt(0, 0) {}  // 또는 pt{0, 0}
};

// C++11 이후는 아래 처럼해도 됩니다.
class Rect
{
	Point pt{ 0,0 }; // <== ok
//	Point pt( 0,0 ); // error. 이 위치는 {}만 가능.
					 // 함수 선언 모양과 충돌..
public:
	Rect() {}
};


int main()
{
	Rect r1;
}

