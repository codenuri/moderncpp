
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
	Rect()
	{
		// 컴파일러 추가 코드
		// call Point::Point(); 
	}
};

int main()
{
	Rect r1;
}

