#include <iostream>

void draw_pixel(int x, int y) {}

int main()
{
	// 5, 5 에 점을 그리고 싶다.
	// 
	// 다음중 좋은 방법은 ?
	
	// 방법 #1. 변수를 만들고 함수 인자로 전달
	int x = 5;
	int y = 5;
	draw_pixel(x, y);

	// 방법 #2. 인자로 literal 사용
	// => 점의 위치를 알수 있다면 변수를 만들필요는 없다.
	draw_pixel(5, 5);	
}





