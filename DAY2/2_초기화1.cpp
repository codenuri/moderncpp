// 필드 초기화 - 55 page
#include <iostream>

class Point
{
	// C++11 부터, 멤버 데이타를 직접 초기화 가능합니다.
	// => member field initialization
	int x = 0;
	int y = 0;
public:
	Point() {}
	Point(int x) : x(x) {}
	Point(int x, int y) : x(x), y(y) {}
};
// 위 코드의 정확한 원리
// => 컴파일러가 아래 처럼 코드를 수정한것
class Point
{	
	int x;// = 0;
	int y;// = 0;
public:
	// 필드 초기값이 있다면 컴파일러가 모든 생성자를 변경
	Point() : x(0), y(0) {}
	Point(int x) : x(x), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
};


int main()
{
}
