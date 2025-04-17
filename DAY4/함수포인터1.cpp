// �Լ� ������1.cpp

class Point
{
	int x, y;
public:
	// �ٽ� #1. ��� �Լ��� ���ڷ� "this" �� �߰��˴ϴ�. - "this call"
	void set(int a, int b)	// void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;		
		y = b;				//		this->y = b;
	}						// }

	// �ٽ� #1. static ��� �Լ��� ���ڷ� "this" �� �߰� �ȵ˴ϴ�.
	static void foo(int n)	// void foo(int n)
	{						// {
		x = a;				//		this->x = a; �� �����ؾ� �ϴµ�
							//				this�� ���⶧���� ����
							//		�׷��� static ��� �Լ���
							//		��� ����Ÿ ���� �ȵ˴ϴ�.
	}
};
int main()
{
	Point::foo(3); // ��ü ���� ȣ��
					// call foo(3)

	Point p1;
	Point p2;

	p1.set(10, 20); // �� ������ ������ ������ ���ô�.
					// set(&p1, 10, 20) ���� �����մϴ�.
}