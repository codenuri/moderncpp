#include <iostream>
// 6_위임생성자 - 24page
class Point
{
public:
	int x, y;
public:
	// 생성자에서 다른 생성자 호출
	// => C++98 안됨
	// => C++11 "위임생성자(delegate constructor)" 문법 사용
	Point() : Point(0, 0)  // <= 위임생성자
	{
//		Point(0, 0);	// 이코드는 생성자 호출 코드가 아닙니다.
						// "임시객체" 를 만드는 표기법입니다.
	}
	Point(int a, int b) : x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

