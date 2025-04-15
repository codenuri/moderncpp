
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
//	Rect() {}		// Rect() : pt1(), pt2() {}
					// => 핵심 : 컴파일러는 항상 멤버데이타의 
					//			디폴트 생성자를 호출하도록 코드 추가

	// 해결책 #1. C++98 스타일
	// => Rect 생성자에서 초기화 리스트 문법으로 
	//    멤버 데이타의 다른 생성자 호출하는 코드를 제공
	//    () 또는 {} 모두 가능
	Rect() : pt1(0, 0), pt2{ 0, 0 } {}
};

// 해결책 #2. C++11 스타일
// => 필드 초기화 사용
class Rect2
{
	Point pt1(0, 0);	// error. () 는 안됩니다.
						// => 컴파일러가 이 표현식을 "멤버함수"로 생각
						// => 인자 위치에 타입이 아닌 0 이 있으므로 에러
	Point pt2{0, 0};	// ok.    {} 만 가능. 
};

int main()
{
	Rect r1;
}

