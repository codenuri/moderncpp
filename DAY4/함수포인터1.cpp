// 함수 포인터1.cpp

class Point
{
	int x, y;
public:
	void set(int a, int b)
	{
		x = a;
		y = b;
	}
};
int main()
{
	Point p1;
	Point p2;

	p1.set(10, 20); // 이 한줄의 원리를 생각해 봅시다.
}