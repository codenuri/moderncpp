
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// �ٽ� : Point Ŭ������ "����Ʈ �����ڰ� ����" �� ��. 
// Point p1;		// error
// Point p2(0,0);	// ok

// �ٽ� : ����Ʈ �����ڰ� ���� Point �� ��� ����Ÿ�� ������
class Rect
{
	Point pt1; 
	Point pt2;
public:
	// �Ʒ� �ڵ尡 ������ ����
	// ����� �ڵ�	// �����Ϸ��� ������ �ڵ�
	Rect() {}		// Rect() : pt1(), pt2() {}
};

int main()
{
	Rect r1;
}

