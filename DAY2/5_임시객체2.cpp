#include <iostream>

void draw_pixel(int x, int y) {}

int main()
{
	// 5, 5 �� ���� �׸��� �ʹ�.
	// 
	// ������ ���� ����� ?
	
	// ��� #1. ������ ����� �Լ� ���ڷ� ����
	int x = 5;
	int y = 5;
	draw_pixel(x, y);

	// ��� #2. ���ڷ� literal ���
	// => ���� ��ġ�� �˼� �ִٸ� ������ �����ʿ�� ����.
	draw_pixel(5, 5);	
}





