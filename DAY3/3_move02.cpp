// move �� ���� �Ϸ��� "���� ������" ���� ��Ȯ�� �˾ƾ� �մϴ�.
// 
// ��������� ����� ������ ���ô�.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// ���� �����ڸ� ���� ����� ���ô�.

	// #1. ���ڸ� call by value
	Point(Point other) {}

};

int main()
{
	Point p1;		// 1 �� ������
	Point p2(1, 2);	// 2 �� ������ 

	Point p3(p2);	// �����Ϸ��� ����� ���� ������ ���				
}




