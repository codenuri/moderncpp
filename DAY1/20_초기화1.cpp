#include <iostream>

class Point
{
	int x = 0;  // C++11 부터 멤버데이타(필드)를 직접 초기화 가능 
	int y = 0;
public:
	Point() {}
	Point(int y)        : y(y) {}
	Point(int x, int y) : x(x), y(y) {}
};

// 위 코드는 컴파일러는 아래 코드로 변경합니다.
class Point
{
	int x;// = 0;
	int y;// = 0;
public:
	// 위 초기값의 내용대로 생성자를 아래 처럼 변경합니다.
	Point()      : x(0), y(0) {}
	Point(int y) : x(0), y(y) {}
	Point(int x, int y) : x(x), y(y) {}
};


int main()
{
	Point pt(1, 1);
}
