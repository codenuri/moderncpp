// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// �ƹ� �ϵ� ���� ���� ����Ʈ �����ڰ� �ʿ��ϸ�

	// #1. �����ڰ� ���� �����ϴ� ���
//	Point() {}

	// #2. �����Ϸ����� ����Ʈ �����ڸ� ����� �޶�� ��û
	// => C++11 ���� ���� �Ǵ� ���� �θ� ���Ǵ� ����
	Point() = default;
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




