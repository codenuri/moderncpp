// - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page
//-----------------------------------------------------------------
void f1(Point  pt) {} // call by value     : 복사본 객체 생성
void f2(Point& pt) {} // call by reference : 복사본 생성 안됨
/*
int main()
{
	Point p{ 0, 0 };
	f1(p);
	f2(p);
}
*/
//------------------------------------------------------------------


Point pt{ 1, 2 };


Point foo() // return by value : 복사본 반환
{
	return pt; // return Point{pt};
}

Point& goo() // return by reference : 복사본 생성 안함
{
	return pt;	// pt 자체를 참조로 반환
}
int main()
{
	foo().x = 10; // error. "리턴용temporary".x = 10 의미 인데
				  // temporary 는 등호의 왼쪽에 올수 없다.
	goo().x = 10; // ok.  "pt별명.x = 10"
}

