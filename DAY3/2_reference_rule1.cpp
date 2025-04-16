// 3_���۷���1.cpp - 89 page - ���� �߿�!

struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	Point pt{ 0, 0 };

	// ��Ģ #1. non-const lvalue reference �� lvalue �� ����ų�� �ִ�.
	Point& r1 = pt;				// ok
	Point& r2 = Point{ 0, 0 };	// error

	// ��Ģ #2. const lvalue reference �� lvalue �� rvalue �� ��� ����Ų��
	const Point& r3 = pt;				// ok
	const Point& r4 = Point{ 0, 0 };	// ok


	// ��Ģ #3. rvalue reference �� rvalue �� ����ų�� �ִ�.
	// => C++11 ���鶧 rvalue(�ӽð�ü) �� const ���� ����ų �ʿ䰡
	//    �־����ϴ�(move �� perfect forwarding �� ����� ����)
	// => �׷��� ���ο� reference ����
	Point&& r3 = pt;			// error
	Point&& r4 = Point{ 0, 0 };	// ok

	// �׷�, "const rvalue reference �� ���� ??"
	// => rvalue �� ����ŵ�ϴ�.
	// => �׷���, ���� ������ ��������� ����� ������ �����ϴ�.
	//    move �� �˾ƾ� �̰� �����Ҽ� �ֽ��ϴ�
}