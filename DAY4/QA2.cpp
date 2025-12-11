// thiscall 이야기

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
	Point p1, p2;
	p1.set(10, 20); // 이 한줄의 정확한 원리를 생각해 봅시다.
	p2.set(10, 20); 
}