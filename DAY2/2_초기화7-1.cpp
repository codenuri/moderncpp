
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
	/*
	Rect()
	{
		// 컴파일러 추가 코드
		// call Point::Point(); 
	}
	*/
	// 해결책 #1. 초기화 리스트에서 () 또는 {} 로 초기화
	Rect() : pt(0, 0)  // 또는 pt{0, 0}
	{
		// 위 초기화 리스트를 보고 컴파일러가 아래 처럼 코드 생성
		// call Point::Point(0, 0); 
	}
};

// 해결책 #2. 필드 초기화에서 {} 초기화 사용
// => C++11 부터 가능
class Rect2
{
	Point pt{ 0, 0 }; // ok
//	Point pt( 0, 0 ); // error. () 는 안됨
					  // 컴파일러가 파싱 하다가 pt 를 함수로 오해!!
					  // => "성가신 파싱 문제." 라는 이름을 가지고 있는 문제
public:
	Rect2()
	{
		// 필드 초기화 때문에 컴파일러가아래 처럼 생성
		// call Point::Point(0,0)
	}
};



int main()
{
	Rect r1;
}

