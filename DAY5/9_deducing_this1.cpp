// 9_deducing_this1
#include <iostream>
// C++23 에서 "1번째" 로 이야기되는 변화!!
// => deducing this 문법

struct Point
{
	int x = 0;
	int y = 0;
	// C++23 이후 아래와 같은 일반적인 멤버 함수를 
	// "implicit object parameter"
	void set1(int a, int b)	// void set1( Point* this, int a, int b)
	{
		x = a;	// this->x = a;
		y = b;  // this->y = b;
	}

	// C++23 : explicit object parameter 라고 불리는 문법
	void set2(this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}
};

int main()
{
	Point pt;
	pt.set1(1, 2); // 컴파일 하면 set1(&pt, 1, 2) 이 됩니다.
	pt.set2(1, 2); // set2(pt, 1, 2)
}