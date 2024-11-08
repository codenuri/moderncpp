// 9_deducing_this1
#include <iostream>

struct Point
{
	int x = 0;
	int y = 0;

	void set1(int a, int b)
	{
		x = a;
		y = b;
	}
};

int main()
{
	Point pt;
	pt.set1(1, 2);
}