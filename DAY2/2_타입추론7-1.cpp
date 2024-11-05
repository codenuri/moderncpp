#include <iostream>

int x = 0;

int  f1() { return x; }	// x의 값 "0" 반환
int& f2() { return x; }	// x의 별명(참조) 반환

int main()
{
	f1() = 20;	// error. "0 = 20" 의 의미 
	f2() = 20;	// ok.    "x별명 = 20"
}
