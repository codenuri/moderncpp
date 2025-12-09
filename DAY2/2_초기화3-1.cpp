#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x{ x }, y{ y } {}
};

void f1(int n) {}
void f2(Point pt) {}

// {} 초기화 때문에 C++ 코드가 많이 유연해 집니다.
int main()
{
	f1(3);	// int n = 3; 형태로 인자 전달
	f1({ 3 });	// int n = {3}; 

	f2({ 1,2 }); // ok. Point pt = {1,2}
	f2({}); // Point 에 디폴트 생성자가 있다면 ok.
}

Point f3() 
{ 
	return { 0,0 }; // Point p ={0,0}; return p;
//	return {}; // Point p; return p;
}

