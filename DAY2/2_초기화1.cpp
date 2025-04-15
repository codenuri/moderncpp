// 초기화 - 55 page
#include <iostream>

class Point
{
	// member field initialization
	// => C++11 부터 멤버 데이타를 직접 초기화 가능
	int x = 0;
	int y = 0;
public:
	Point() {}
	Point(int x) : x(x) {}
	Point(int x, int y) : x(x), y(y) {}
};

// 필드 초기화의 정확한 원리
// => 컴파일러가 위 코드를 아래 처럼 변경합니다.
class Point
{
	int x;// = 0;
	int y;// = 0;
public:
	// 모든 생성자를 위 초기값을 사용하도록 변경합니다.
	Point()		 : x(0), y(0) {}
	Point(int x) : x(x), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
};
int main()
{
}
