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

int main()
{
	f1(3);	    // int n = 3
	f1({ 3 });	// int n = {3}

	f2({ 1, 2 }); // Point pt = {1,2}
	f2({});		  // ok  Point pt = {}. ����Ʈ ������ ȣ��
}

Point f3() { return { 0,0 }; } // ok
			// return Point{0,0} �� ����, ��, �ӽð�ü ��ȯ
