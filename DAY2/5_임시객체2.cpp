#include <iostream>

void draw_pixel(int x, int y) {}

int main()
{
	// 5, 5 의 위치에 점을 그리고 싶다 
	
	// #1. 변수를 만든후에 전달
	int x = 5;
	int y = 5;
	draw_pixel(x, y);

	// #2. 리터럴을 직접 사용
	draw_pixel(5, 5);	

	// 당연히 2번이 좋은 코드!!! 5, 5 라는 정해진 값이라면
	// 변수 만들 필요 없다.!
}





