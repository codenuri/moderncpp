#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4);
}
