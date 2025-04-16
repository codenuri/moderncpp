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
	// => �� ǥ����� "��������ڰ� ������ ȣ��" �Ǵ� ǥ���
	// => ���� ������ ���ڴ� "�� Ÿ��"�� �ɼ� �����ϴ�
//	Point(Point other) {}

	// #2. ���ڴ� non-const lvalue reference
	// => ������ ������ �ƴ�.
	// => �ӽð�ü(rvalue) �� ������ ����.
	// => Point ret = foo() �ڵ尡 ������ ����!
//	Point(Point& other) {}

	// #3. const lvalue reference
	// => lvalue �� rvalue �� ��� ������ �ִ�.
	// => �̷� ���� ������ ���� �������� ���ڸ� "const lvalue reference"��
	//    ����� ���Դϴ�.
	Point(const Point& other) : x(other.x), y(other.y) {}

};

Point foo() { return Point{ 1,1 }; }

int main()
{
	Point p1;		// 1 �� ������
	Point p2(1, 2);	// 2 �� ������ 

	Point p3(p2);	// �����Ϸ��� ����� ���� ������ ���	
					// Point other = p2

	Point ret = foo(); // Point ret(foo());
}




