// �ʱ�ȭ - 55 page
#include <iostream>

class Point
{
	// member field initialization
	// => C++11 ���� ��� ����Ÿ�� ���� �ʱ�ȭ ����
	int x = 0;
	int y = 0;
public:
	Point() {}
	Point(int x) : x(x) {}
	Point(int x, int y) : x(x), y(y) {}
};

// �ʵ� �ʱ�ȭ�� ��Ȯ�� ����
// => �����Ϸ��� �� �ڵ带 �Ʒ� ó�� �����մϴ�.
class Point
{
	int x;// = 0;
	int y;// = 0;
public:
	// ��� �����ڸ� �� �ʱⰪ�� ����ϵ��� �����մϴ�.
	Point()		 : x(0), y(0) {}
	Point(int x) : x(x), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
};
int main()
{
}
