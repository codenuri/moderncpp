#include <stdio.h>

int main()
{
	int x[2] = {1,2};
	
	int (*p1)[2] = &x; // 배열의 주소
	int *p2 = x;	   // 배열의 1번째 요소의 주소

	int y[2][2] = {1,2,3,4};
	? p3 = &y;
	? p4 = y;

	int z[2][2][2] = {1,2,3,4};
	? p5 = &z;
	? p6 = z;
}
