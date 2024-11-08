﻿// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page
void f1(Point  pt) {}	// call by value     : 복사본 생성
void f2(Point& pt) {}	// call by reference : 복사본 생성 안됨

/*
int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/
//===========================================






Point pt(1, 2);

Point foo()		// return by value : 임시객체를 반환
{
	return pt;  // 1. pt를 복사한 임시객체 생성 
}				// 2. 임시객체 반환

Point& goo()	// return by reference 
{				// => 리턴용 임시객체를 만들지 말라.
	return pt;
}
int main()
{
	foo().x = 10; // error. "임시객체.x = 10"
	goo().x = 10; // ok.    "pt.x = 10"
}

// 주의 : 지역변수는 절대로 참조리턴하면 안됩니다.
// => 전역변수나, 멤버 데이타 처럼 파괴되지 않은 것만 참조 반환가능
Point& hoo()
{
	Point p(1, 2);
	return p; // 버그. 에러는 없지만 경고!!
}

