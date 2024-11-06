#include <iostream>

// function object(함수 객체)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

struct Plus
{
	int operator()(int a, int b) 
	{
		return a + b;
	}
};


int main()
{
	Plus p;		

	int n = p(1, 2);	
	
}
