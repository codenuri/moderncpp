
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// 핵심 : 디폴트 생성자가 없는 타입을 멤버 데이타로 사용하는 방법

class Rect
{
	Point pt; // ?
public:
	Rect()
	{
		// Rect 생성자에서는 반드시 모든 멤버 데이타의 생성자를 호출해야 합니다.
		// 그래서 컴파일러가 아래 코드를 추가합니다
		// call Point::Point(); // 멤버 데이타인 pt에 대해서 생성자 호출.

		// 하지만 현재 Point 는 디폴트 생성자가 없으므로 "컴파일 에러"
	}
};

int main()
{
	Rect r1;
}

