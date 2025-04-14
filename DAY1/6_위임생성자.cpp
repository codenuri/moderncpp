#include <iostream>
// 6_위임생성자 - 24page
class Point
{
public:
	int x, y;
public:
	// C++11 부터 생성자에서 다른 생성자 호출 가능합니다
	Point() : Point(0,0)  // <== 위임 생성자라는 문법
	{
		// 생성자 안에서 "다른 생성자 호출??" 될까요 ?
		// => 아래 처럼은 안됩니다.
		// => 그런데, 아래 코드가 에러도 아닙니다.
		// => "임시객체"를 만드는 표기법이므로!!
		//    즉, 새로운 객체 생성(임시객체는 내일 자세히)
		// => C++11 부터는 위 코드(위임생성자)를 사용하면 가능
		Point(0, 0);
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

