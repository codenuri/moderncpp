#include <iostream>

struct Point
{
	int x = 0;
	int y = 0;

	void set(int a, int b)
	{
		x = a;	
		y = b;  
	}
	void print()
	{
		std::cout << x << std::endl;
	}
};
int main()
{
	Point pt;

	pt.x = 10;
	pt.set(10, 20);
	pt.print();	
}