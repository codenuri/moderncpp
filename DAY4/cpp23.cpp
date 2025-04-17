class Point
{
	int x, y;
public:
	void set(int a, int b)	// void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;		
		y = b;				//		this->y = b;
	}						// }

	// C++23 ���� �����ϴ� ��û�� ��ȭ!!!
	// => �����Ϸ��� this �� �߰��ϴ� ���� �ƴ϶� 
	// => �����ڰ� ���� �޵�� �ֽ��ϴ�.
	// => �Ʒ� �ڵ�� ���� ������ �����մϴ�.
	// => visual studio �� ���� ����
	void set2(this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}

};
int main()
{
	Point p1;

	p1.set(10, 20);
	p1.set2(10, 20);

}